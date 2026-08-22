/*
 * p3Ej1c.c — Multiplicación por bloques C = A * B  (MPI + blocking)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : De datos por tiras de filas de A (→ tiras de C).
 *                  Igual que p3Ej1a, pero el kernel local usa blocking para
 *                  mejorar la localidad espacial/temporal en caché (L1/L2).
 * Comunicación   : Scatter(A), Bcast(B), Gather(C). Idéntico a naive.
 * Aglomeración   : N/P filas de A por proceso, subdivididas en bloques BS×BS.
 * Mapeo          : Estático. Carga uniforme.
 *
 * Mejora respecto a naive: el kernel interno accede a bloques de tamaño BS×BS
 * de A y B que caben en caché, reduciendo cache misses (Principio de Localidad).
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej1c p3Ej1c.c
 * Ejecutar: mpirun -np <P> ./p3Ej1c <N> <BS> <A> <B> <R>
 *
 * Variante mmblk_blas (bloques + transposición local, sin librería externa):
 *   mpicc -O2 -DUSE_BLAS -o p3Ej1c_blas p3Ej1c.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

static inline int min2(int a, int b) { return a < b ? a : b; }

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
    int rank, size, N, local_n, BS;
    double *A = NULL, *B = NULL, *C = NULL;
    double *local_A, *local_C;
    const char *pathA = NULL, *pathB = NULL, *pathR = NULL;
    double t0, t1;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 6) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej1c N BS <A> <B> <R>\n");
        MPI_Finalize(); return 1;
    }
    N  = atoi(argv[1]);
    BS = atoi(argv[2]);
    pathA = argv[3];
    pathB = argv[4];
    pathR = argv[5];

    if (N % size != 0) {
        if (!rank) fprintf(stderr, "Error: N=%d no es divisible por P=%d\n", N, size);
        MPI_Finalize(); return 1;
    }
    local_n = N / size;

    local_A = (double *)malloc(local_n * N * sizeof(double));
    local_C = (double *)malloc(local_n * N * sizeof(double));
    B       = (double *)malloc(N * N * sizeof(double));

    if (rank == 0) {
        A = (double *)malloc(N * N * sizeof(double));
        C = (double *)malloc(N * N * sizeof(double));
        leerMatriz(A, N, pathA);
        leerMatriz(B, N, pathB);
    }

    t0 = MPI_Wtime();

    MPI_Bcast(B, N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(A, local_n*N, MPI_DOUBLE,
                local_A, local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    /* ── Kernel por bloques (o BLAS si compilado con -DUSE_BLAS) ─────────── */
    for (int i = 0; i < local_n * N; i++) local_C[i] = 0.0;

#ifdef USE_BLAS
    /* mmblk_blas: bloques BS×BS con transposición local de B (idéntico a cátedra).
       B está column-major en disco/memoria → se reordena a row-major en btmp
       para aprovechar acceso secuencial dentro del bloque. */
    {
        double *btmp = (double *)malloc((size_t)BS * BS * sizeof(double));
        for (int I = 0; I < local_n; I += BS) {
            int I_end = I + BS < local_n ? I + BS : local_n;
            for (int J = 0; J < N; J += BS) {
                /* inicializar bloque resultado */
                for (int i = I; i < I_end; i++)
                    for (int j = J; j < J + BS; j++)
                        local_C[i*N+j] = 0.0;
                for (int K = 0; K < N; K += BS) {
                    /* reordenar bloque de B column-major → btmp row-major */
                    for (int i = 0; i < BS; i++)
                        for (int j = 0; j < BS; j++)
                            btmp[i*BS+j] = B[(J+j)*N+(K+i)]; /* B[K+i][J+j] col-major */
                    /* multiplicar bloque A × btmp */
                    for (int i = I; i < I_end; i++)
                        for (int j = 0; j < BS; j++) {
                            double sum = 0.0;
                            for (int k = 0; k < BS; k++)
                                sum += local_A[i*N+(K+k)] * btmp[k*BS+j];
                            local_C[i*N+(J+j)] += sum;
                        }
                }
            }
        }
        free(btmp);
    }
#else
    /* Blocking manual: orden i-kk-jj-k-j para mejor localidad */
    for (int ii = 0; ii < local_n; ii += BS)
        for (int kk = 0; kk < N; kk += BS)
            for (int jj = 0; jj < N; jj += BS)
                for (int i = ii; i < min2(ii+BS, local_n); i++)
                    for (int k = kk; k < min2(kk+BS, N); k++) {
                        double a_ik = local_A[i*N+k];
                        int j_end   = min2(jj+BS, N);
                        for (int j = jj; j < j_end; j++)
                            local_C[i*N+j] += a_ik * B[j*N+k];  /* B column-major */
                    }
#endif

    MPI_Gather(local_C, local_n*N, MPI_DOUBLE,
               C,       local_n*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    t1 = MPI_Wtime();

    if (rank == 0) {
        int ok = (validar(N, C, pathR) == 0);
        printf("N=%d  BS=%d  P=%d  Tiempo=%.6f s  Validacion=%s\n",
               N, BS, size, t1-t0, ok ? "OK" : "FALLO");
        free(A); free(C);
    }
    free(local_A); free(local_C); free(B);
    MPI_Finalize();
    return 0;
}
