/*
 * p3Ej1b.c — Autoproducto de matrices C = A * A  (MPI)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos por filas de A. Cada fila i de C se calcula como
 *                  producto interno de la fila i de A con TODAS las columnas
 *                  de A → las filas de C son independientes entre sí.
 * Comunicación   : Broadcast de A completa (se usa como "B"), Scatter de N/P
 *                  filas de A (se usa como "fila local"), Gather de C.
 *                  Observación: el Bcast domina la comunicación — O(N²) datos.
 * Aglomeración   : N/P filas contiguas por proceso.
 * Mapeo          : Estático. Carga perfectamente uniforme.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej1b p3Ej1b.c
 * Ejecutar: mpirun -np <P> ./p3Ej1b <N> <A>
 *
 * Validación: rank 0 computa A×A secuencial (ikj) y compara con resultado
 *             paralelo. No requiere archivo de referencia externo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mpi.h>

static double *leerMatriz(double *m, int n, const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); exit(1); }
    if (fread(m, sizeof(double), (size_t)n * n, f) != (size_t)n * n) {
        fprintf(stderr, "Error leyendo %s\n", path);
        fclose(f); exit(1);
    }
    fclose(f);
    return m;
}

/* Calcula C = A*A secuencial (ikj) — usado solo en rank 0 para validar */
static void matmul_aa(const double *A, double *C, int N)
{
    memset(C, 0, (size_t)N * N * sizeof(double));
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++) {
            double a_ik = A[i*N+k];
            for (int j = 0; j < N; j++)
                C[i*N+j] += a_ik * A[k*N+j];
        }
}

int main(int argc, char *argv[])
{
    int rank, size, N, local_n;
    double *A = NULL, *A_full, *C = NULL, *C_seq = NULL, *local_A, *local_C;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 3) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej1b N <A>\n");
        MPI_Finalize(); return 1;
    }
    N = atoi(argv[1]);
    if (N % size != 0) {
        if (!rank) fprintf(stderr, "Error: N=%d no es divisible por P=%d\n", N, size);
        MPI_Finalize(); return 1;
    }
    local_n = N / size;

    A_full  = (double *)malloc(N * N * sizeof(double));
    local_A = (double *)malloc(local_n * N * sizeof(double));
    local_C = (double *)malloc(local_n * N * sizeof(double));

    if (rank == 0) {
        A     = (double *)malloc(N * N * sizeof(double));
        C     = (double *)malloc(N * N * sizeof(double));
        C_seq = (double *)malloc(N * N * sizeof(double));
        leerMatriz(A, N, argv[2]);
        /* Referencia secuencial (fuera de la medición) */
        matmul_aa(A, C_seq, N);
    }

    t0 = MPI_Wtime();

    /* ── Paso 1: Broadcast de A completa ────────────────────────────────── */
    if (rank == 0)
        memcpy(A_full, A, (size_t)N * N * sizeof(double));
    MPI_Bcast(A_full, N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Paso 2: Scatter de N/P filas de A ──────────────────────────────── */
    MPI_Scatter(A, local_n*N, MPI_DOUBLE,
                local_A, local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Paso 3: C_local = local_A * A_full (ikj, caché-friendly) ───────── */
    for (int i = 0; i < local_n * N; i++) local_C[i] = 0.0;
    for (int i = 0; i < local_n; i++)
        for (int k = 0; k < N; k++) {
            double a_ik = local_A[i*N+k];
            for (int j = 0; j < N; j++)
                local_C[i*N+j] += a_ik * A_full[k*N+j];
        }

    /* ── Paso 4: Gather de C ────────────────────────────────────────────── */
    MPI_Gather(local_C, local_n*N, MPI_DOUBLE,
               C,       local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    t1 = MPI_Wtime();

    /* ── Validación inline (rank 0 compara C paralelo con C_seq) ─────────── */
    if (rank == 0) {
        int ok = 1;
        for (int i = 0; i < N * N && ok; i++)
            if (fabs(C[i] - C_seq[i]) > 1e-10) ok = 0;
        printf("N=%d  P=%d  Tiempo=%.6f s  Validacion=%s\n",
               N, size, t1-t0, ok ? "OK" : "FALLO");
        free(A); free(C); free(C_seq);
    }
    free(A_full); free(local_A); free(local_C);
    MPI_Finalize();
    return 0;
}
