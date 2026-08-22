/*
 * p3Ej3.c — Transposición de matriz cuadrada N×N  (MPI + MPI_Alltoall)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos. Cada elemento (i,j) de A produce T[j][i] → N²
 *                  tareas independientes.
 * Comunicación   : El problema es inherentemente no local: la fila i de A
 *                  se convierte en la columna i de T (que está en otro proceso).
 *                  Se usa MPI_Alltoall para redistribuir bloques de datos entre
 *                  todos los procesos → comunicación all-to-all estructurada.
 * Aglomeración   : Cada proceso maneja N/P filas de A y produce N/P filas de T.
 *                  Los bloques de local_n × local_n se intercambian vía Alltoall.
 * Mapeo          : Estático. Carga uniforme.
 *
 * Algoritmo (verificado algebraicamente):
 *   1. Scatter: proceso p recibe filas [p·local_n .. (p+1)·local_n − 1] de A.
 *   2. Empaquetado: para cada destino q, copiar el sub-bloque de A de columnas
 *      [q·local_n .. (q+1)·local_n − 1] → send_buf[q·local_n² + i·local_n + k].
 *   3. MPI_Alltoall: intercambia bloques de local_n² doubles entre todos.
 *   4. Desempaquetado: recv_buf[q·local_n² + i·local_n + k] = T[local_n·k][q·local_n+i]
 *      → local_T[k·N + q·local_n + i] = recv_buf[q·local_n² + i·local_n + k].
 *   5. Gather: reconstruir T en rank 0.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej3 p3Ej3.c
 * Ejecutar: mpirun -np <P> ./p3Ej3 <N>        (N divisible por P)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, N, local_n;
    double *A = NULL, *T = NULL;
    double *local_A, *local_T, *send_buf, *recv_buf;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 2) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej3 N\n");
        MPI_Finalize(); return 1;
    }
    N = atoi(argv[1]);
    if (N % size != 0) {
        if (!rank) fprintf(stderr, "Error: N=%d no divisible por P=%d\n", N, size);
        MPI_Finalize(); return 1;
    }
    local_n = N / size;

    local_A  = (double *)malloc(local_n * N * sizeof(double));
    local_T  = (double *)malloc(local_n * N * sizeof(double));
    send_buf = (double *)malloc(local_n * N * sizeof(double)); /* local_n*N == size*local_n² */
    recv_buf = (double *)malloc(local_n * N * sizeof(double));

    if (rank == 0) {
        A = (double *)malloc(N * N * sizeof(double));
        T = (double *)malloc(N * N * sizeof(double));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i*N+j] = (double)(i*N + j + 1);  /* valores únicos para validar */
    }

    t0 = MPI_Wtime();

    /* ── Paso 1: Scatter filas de A ─────────────────────────────────────── */
    MPI_Scatter(A, local_n*N, MPI_DOUBLE,
                local_A, local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Paso 2: Empaquetar send_buf ─────────────────────────────────────── */
    /* Para destino q, enviar el sub-bloque local_n × local_n de A en cols [q·ln..(q+1)·ln-1] */
    for (int q = 0; q < size; q++)
        for (int i = 0; i < local_n; i++)
            for (int k = 0; k < local_n; k++)
                send_buf[q*local_n*local_n + i*local_n + k] = local_A[i*N + q*local_n + k];

    /* ── Paso 3: Alltoall — cada proceso envía/recibe bloques de local_n² ─ */
    MPI_Alltoall(send_buf, local_n*local_n, MPI_DOUBLE,
                 recv_buf, local_n*local_n, MPI_DOUBLE,
                 MPI_COMM_WORLD);

    /* ── Paso 4: Desempaquetar recv_buf → local_T ────────────────────────── */
    /* recv_buf[q·ln² + i·ln + k] = A[q·ln+i][rank·ln+k] = T[rank·ln+k][q·ln+i] */
    for (int q = 0; q < size; q++)
        for (int i = 0; i < local_n; i++)
            for (int k = 0; k < local_n; k++)
                local_T[k*N + q*local_n + i] = recv_buf[q*local_n*local_n + i*local_n + k];

    /* ── Paso 5: Gather T ────────────────────────────────────────────────── */
    MPI_Gather(local_T, local_n*N, MPI_DOUBLE,
               T,       local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    t1 = MPI_Wtime();

    /* ── Validación: T[j][i] debe ser igual a A[i][j] ───────────────────── */
    if (rank == 0) {
        int ok = 1;
        for (int i = 0; i < N && ok; i++)
            for (int j = 0; j < N && ok; j++)
                if (fabs(T[j*N+i] - A[i*N+j]) > 1e-9) ok = 0;
        printf("N=%d  P=%d  Tiempo=%.6f s  Validacion=%s\n",
               N, size, t1-t0, ok ? "OK (T[j][i]==A[i][j])" : "FALLO");
        free(A); free(T);
    }
    free(local_A); free(local_T); free(send_buf); free(recv_buf);
    MPI_Finalize();
    return 0;
}
