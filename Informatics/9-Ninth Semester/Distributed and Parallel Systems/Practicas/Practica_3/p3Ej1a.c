/*
 * p3Ej1a.c — Multiplicación de matrices C = A * B  (MPI, naive optimizado)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos por filas de A (→ filas de C). Cada fila i de C
 *                  depende solo de la fila i de A y de TODA B → independencia
 *                  total entre filas de C.
 * Comunicación   : Scatter de N/P filas de A, Bcast de B completa,
 *                  Gather de N/P filas de C. Comunicación estructurada y global.
 * Aglomeración   : Bloque de N/P filas contiguas por proceso. Granularidad
 *                  gruesa → minimiza overhead de comunicación.
 * Mapeo          : Estático. Carga uniforme: cada proceso realiza exactamente
 *                  (N/P)·N² operaciones punto-flotante.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej1a p3Ej1a.c
 * Ejecutar: mpirun -np <P> ./p3Ej1a <N> <A> <B> <R>
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

static double *leerMatriz(double *m, int n, const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) {
        perror(path);
        exit(1);
    }
    if (fread(m, sizeof(double), (size_t)n * n, f) != (size_t)n * n) {
        fprintf(stderr, "Error leyendo matriz %s\n", path);
        fclose(f);
        exit(1);
    }
    fclose(f);
    return m;
}

static int validar(int n, const double *c, const char *path)
{
    double *r = (double *)malloc((size_t)n * n * sizeof(double));
    if (!r) return -1;
    leerMatriz(r, n, path);
    for (int i = 0; i < n * n; i++) {
        if (fabs(r[i] - c[i]) > 1e-10) {
            free(r);
            return -1;
        }
    }
    free(r);
    return 0;
}

int main(int argc, char *argv[])
{
    int rank, size, N, local_n;
    double *A = NULL, *B = NULL, *C = NULL;
    double *local_A, *local_C;
    const char *pathA = NULL, *pathB = NULL, *pathR = NULL;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 5) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej1a N <A> <B> <R>\n");
        MPI_Finalize(); return 1;
    }
    N = atoi(argv[1]);
    pathA = argv[2];
    pathB = argv[3];
    pathR = argv[4];
    if (N % size != 0) {
        if (!rank) fprintf(stderr, "Error: N=%d no es divisible por P=%d\n", N, size);
        MPI_Finalize(); return 1;
    }
    local_n = N / size;

    /* ── Memoria ─────────────────────────────────────────────────────────── */
    local_A = (double *)malloc(local_n * N * sizeof(double));
    local_C = (double *)malloc(local_n * N * sizeof(double));
    B       = (double *)malloc(N * N * sizeof(double));  /* cada proceso tiene B */

    if (rank == 0) {
        A = (double *)malloc(N * N * sizeof(double));
        C = (double *)malloc(N * N * sizeof(double));
        leerMatriz(A, N, pathA);
        leerMatriz(B, N, pathB);
    }

    t0 = MPI_Wtime();

    /* ── Paso 1: Broadcast de B ──────────────────────────────────────────── */
    MPI_Bcast(B, N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Paso 2: Scatter de filas de A ──────────────────────────────────── */
    MPI_Scatter(A, local_n*N, MPI_DOUBLE,
                local_A, local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Paso 3: Multiplicación local (optimización: k externo para caché) ─ */
    for (int i = 0; i < local_n; i++)
        for (int j = 0; j < N; j++)
            local_C[i*N+j] = 0.0;

    for (int i = 0; i < local_n; i++)
        for (int k = 0; k < N; k++) {
            double a_ik = local_A[i*N+k];
            for (int j = 0; j < N; j++)
                local_C[i*N+j] += a_ik * B[j*N+k];  /* B column-major: B[k][j] = B[j*N+k] */
        }

    /* ── Paso 4: Gather de C ─────────────────────────────────────────────── */
    MPI_Gather(local_C, local_n*N, MPI_DOUBLE,
               C,       local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    t1 = MPI_Wtime();

    /* ── Validación y resultado (solo rank 0) ────────────────────────────── */
    if (rank == 0) {
        int ok = (validar(N, C, pathR) == 0);
        printf("N=%d  P=%d  Tiempo=%.6f s  Validacion=%s\n",
               N, size, t1-t0, ok ? "OK" : "FALLO");
        free(A); free(C);
    }
    free(local_A); free(local_C); free(B);
    MPI_Finalize();
    return 0;
}
