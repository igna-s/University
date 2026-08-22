/*
 * p3Ej5.c — Merge Sort paralelo  (MPI, árbol binario de fusiones)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos. El arreglo de N enteros se divide en P partes
 *                  iguales de N/P elementos cada una → P tareas independientes
 *                  de ordenamiento local.
 * Comunicación   : Árbol binario de reducción (log₂P rondas):
 *                    Ronda 0: procesos impares envían a pares, pares fusionan.
 *                    Ronda r: proceso con rank%(2^(r+1)) == 0 recibe de
 *                             rank+2^r y fusiona.
 *                  Comunicación estructurada, síncrona (MPI_Send/Recv).
 * Aglomeración   : N/P elementos por proceso para ordenamiento local (qsort),
 *                  luego fusiones de tamaño creciente (2N/P, 4N/P, ..., N).
 * Mapeo          : Estático. Carga razonablemente uniforme en el sort local
 *                  (todos N/P elementos). En las fusiones, la carga baja
 *                  exponencialmente → los procesos terminan y quedan inactivos.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej5 p3Ej5.c
 * Ejecutar: mpirun -np <P> ./p3Ej5 <N>        (N divisible por P, P potencia de 2)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

/* ── Función de comparación para qsort ──────────────────────────────────── */
int cmp_int(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

/* ── Fusión de dos arreglos ordenados en uno ordenado ───────────────────── */
int *merge_sorted(int *left, int ln, int *right, int rn)
{
    int *result = (int *)malloc((ln + rn) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < ln && j < rn)
        result[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < ln) result[k++] = left[i++];
    while (j < rn) result[k++] = right[j++];
    return result;
}

/* ── Verificar que un arreglo está ordenado ──────────────────────────────── */
int is_sorted(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
        if (arr[i] > arr[i+1]) return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    int rank, size, N, local_n;
    int *data = NULL, *local_data, *recv_data, *merged;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 2) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej5 N\n");
        MPI_Finalize(); return 1;
    }
    N = atoi(argv[1]);
    if (N % size != 0) {
        if (!rank) fprintf(stderr, "Error: N=%d no divisible por P=%d\n", N, size);
        MPI_Finalize(); return 1;
    }
    local_n = N / size;

    local_data = (int *)malloc(N * sizeof(int));  /* crecer hasta N al fusionar */

    if (rank == 0) {
        data = (int *)malloc(N * sizeof(int));
        srand(42);
        for (int i = 0; i < N; i++)
            data[i] = rand() % (N * 10);
    }

    t0 = MPI_Wtime();

    /* ── Paso 1: Scatter — cada proceso recibe N/P enteros ──────────────── */
    MPI_Scatter(data, local_n, MPI_INT,
                local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    /* ── Paso 2: Ordenamiento local con qsort ────────────────────────────── */
    qsort(local_data, local_n, sizeof(int), cmp_int);

    int cur_size = local_n;  /* tamaño actual del arreglo local */

    /* ── Paso 3: Árbol binario de fusiones (log₂P rondas) ───────────────── */
    for (int stride = 1; stride < size; stride <<= 1) {
        if (rank % (2 * stride) == 0) {
            /* Este proceso RECIBE del proceso rank+stride y fusiona */
            int partner = rank + stride;
            if (partner < size) {
                int recv_size = cur_size;  /* el partner tiene el mismo tamaño */
                recv_data = (int *)malloc(recv_size * sizeof(int));
                MPI_Recv(recv_data, recv_size, MPI_INT, partner, 0,
                         MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                merged = merge_sorted(local_data, cur_size, recv_data, recv_size);
                free(recv_data);
                free(local_data);
                local_data = merged;
                cur_size  += recv_size;
            }
        } else if (rank % stride == 0) {
            /* Este proceso ENVÍA al proceso rank-stride y termina */
            int partner = rank - stride;
            MPI_Send(local_data, cur_size, MPI_INT, partner, 0, MPI_COMM_WORLD);
            break;  /* este proceso no participa en más rondas */
        }
    }

    t1 = MPI_Wtime();

    /* ── Proceso 0 tiene el arreglo completo ordenado ───────────────────── */
    if (rank == 0) {
        /* Validación: comparar con arreglo original ordenado secuencialmente */
        int *seq_sorted = (int *)malloc(N * sizeof(int));
        memcpy(seq_sorted, data, N * sizeof(int));
        qsort(seq_sorted, N, sizeof(int), cmp_int);

        int ok = 1;
        for (int i = 0; i < N && ok; i++)
            if (local_data[i] != seq_sorted[i]) ok = 0;

        printf("N=%d  P=%d  Tiempo=%.6f s  Validacion=%s\n",
               N, size, t1-t0, ok ? "OK (igual a qsort secuencial)" : "FALLO");
        printf("  Primeros 5: %d %d %d %d %d\n",
               local_data[0], local_data[1], local_data[2],
               local_data[3], local_data[4]);
        printf("  Ultimos  5: %d %d %d %d %d\n",
               local_data[N-5], local_data[N-4], local_data[N-3],
               local_data[N-2], local_data[N-1]);

        free(seq_sorted);
        free(data);
    }
    free(local_data);
    MPI_Finalize();
    return 0;
}
