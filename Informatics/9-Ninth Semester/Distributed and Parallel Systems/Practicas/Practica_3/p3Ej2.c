/*
 * p3Ej2.c — Mínimo, máximo y promedio de una matriz N×N  (MPI)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos. La matriz se trata como un arreglo lineal de N²
 *                  elementos. Cada elemento contribuye de forma independiente
 *                  al min, max y suma → N² tareas atómicas.
 * Comunicación   : Scatter de N²/P elementos, luego MPI_Reduce con operaciones
 *                  MPI_MIN, MPI_MAX y MPI_SUM. Comunicación mínima (O(P)).
 * Aglomeración   : Bloque de N²/P elementos contiguos por proceso.
 * Mapeo          : Estático. Carga perfectamente uniforme.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej2 p3Ej2.c
 * Ejecutar: mpirun -np <P> ./p3Ej2 <N>
 */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, N, total, local_n;
    double *A = NULL, *local_A;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 2) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej2 N\n");
        MPI_Finalize(); return 1;
    }
    N = atoi(argv[1]);
    total = N * N;

    if (total % size != 0) {
        if (!rank) fprintf(stderr, "Error: N²=%d no divisible por P=%d\n", total, size);
        MPI_Finalize(); return 1;
    }
    local_n = total / size;
    local_A = (double *)malloc(local_n * sizeof(double));

    /* Inicialización en rank 0 */
    if (rank == 0) {
        A = (double *)malloc(total * sizeof(double));
        srand(42);
        for (int i = 0; i < total; i++)
            A[i] = (double)rand() / RAND_MAX * 1000.0;  /* [0, 1000) */
    }

    t0 = MPI_Wtime();

    /* ── Scatter: cada proceso recibe N²/P elementos ─────────────────────── */
    MPI_Scatter(A, local_n, MPI_DOUBLE,
                local_A, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Reducción local ─────────────────────────────────────────────────── */
    double local_min = DBL_MAX, local_max = -DBL_MAX, local_sum = 0.0;
    for (int i = 0; i < local_n; i++) {
        if (local_A[i] < local_min) local_min = local_A[i];
        if (local_A[i] > local_max) local_max = local_A[i];
        local_sum += local_A[i];
    }

    /* ── MPI_Reduce: mínimo global, máximo global, suma global ──────────── */
    double global_min, global_max, global_sum;
    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    t1 = MPI_Wtime();

    /* ── Validación y reporte ────────────────────────────────────────────── */
    if (rank == 0) {
        double seq_min = DBL_MAX, seq_max = -DBL_MAX, seq_sum = 0.0;
        for (int i = 0; i < total; i++) {
            if (A[i] < seq_min) seq_min = A[i];
            if (A[i] > seq_max) seq_max = A[i];
            seq_sum += A[i];
        }
        int ok = (fabs(global_min - seq_min) < 1e-9 &&
                  fabs(global_max - seq_max) < 1e-9 &&
                  fabs(global_sum - seq_sum) < 1e-6 * seq_sum);

        printf("N=%d  P=%d  Tiempo=%.6f s\n", N, size, t1-t0);
        printf("  Min=%.6f  Max=%.6f  Promedio=%.6f\n",
               global_min, global_max, global_sum / total);
        printf("  Validacion=%s\n", ok ? "OK" : "FALLO");
        free(A);
    }
    free(local_A);
    MPI_Finalize();
    return 0;
}
