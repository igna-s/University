/*
 * gen_ref.c — Genera matrices de entrada y resultados de referencia para
 *             validar los programas MPI de práctica 3.
 *
 * Uso: ./gen_ref N
 *   Genera en el directorio actual:
 *     mats/AN.m   — matriz A (N×N, doubles aleatorios en [0,1))
 *     mats/BN.m   — matriz B (N×N, doubles aleatorios en [0,1))
 *     mats/RABN.m — resultado A×B  (para Ej1a y Ej1c)
 *     mats/RAAN.m — resultado A×A  (para Ej1b)
 *
 * Ambas matrices y resultados usan almacenamiento row-major, igual que
 * el kernel paralelo de p3Ej1a/1b/1c.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>

static double wtime(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

static void write_mat(const double *m, int n, const char *path)
{
    FILE *f = fopen(path, "wb");
    if (!f) { perror(path); exit(1); }
    if (fwrite(m, sizeof(double), (size_t)n * n, f) != (size_t)n * n) {
        fprintf(stderr, "Error escribiendo %s\n", path);
        fclose(f); exit(1);
    }
    fclose(f);
    printf("  Escrito: %s\n", path);
}

/* Multiplicación ikj (cache-friendly) para generar referencia */
static void matmul(const double *A, const double *B, double *C, int N)
{
    memset(C, 0, (size_t)N * N * sizeof(double));
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++) {
            double a_ik = A[i * N + k];
            for (int j = 0; j < N; j++)
                C[i * N + j] += a_ik * B[k * N + j];
        }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s N\n", argv[0]);
        return 1;
    }
    int N = atoi(argv[1]);
    if (N <= 0) { fprintf(stderr, "N debe ser > 0\n"); return 1; }

    mkdir("mats", 0755);

    char pA[64], pB[64], pRAB[64], pRAA[64];
    snprintf(pA,   sizeof(pA),   "mats/A%d.m",   N);
    snprintf(pB,   sizeof(pB),   "mats/B%d.m",   N);
    snprintf(pRAB, sizeof(pRAB), "mats/RAB%d.m", N);
    snprintf(pRAA, sizeof(pRAA), "mats/RAA%d.m", N);

    size_t sz = (size_t)N * N;
    double *A   = malloc(sz * sizeof(double));
    double *B   = malloc(sz * sizeof(double));
    double *RAB = malloc(sz * sizeof(double));
    double *RAA = malloc(sz * sizeof(double));
    if (!A || !B || !RAB || !RAA) { perror("malloc"); return 1; }

    printf("N=%d  Generando matrices...\n", N);

    /* Genera A y B con semillas diferentes y reproducibles */
    srand(42);
    for (size_t i = 0; i < sz; i++)
        A[i] = (double)rand() / RAND_MAX;
    srand(137);
    for (size_t i = 0; i < sz; i++)
        B[i] = (double)rand() / RAND_MAX;

    write_mat(A, N, pA);
    write_mat(B, N, pB);

    double t0 = wtime();
    printf("  Calculando A*B (referencia para Ej1a/1c)...\n");
    matmul(A, B, RAB, N);
    printf("  A*B listo en %.2f s\n", wtime() - t0);
    write_mat(RAB, N, pRAB);

    t0 = wtime();
    printf("  Calculando A*A (referencia para Ej1b)...\n");
    matmul(A, A, RAA, N);
    printf("  A*A listo en %.2f s\n", wtime() - t0);
    write_mat(RAA, N, pRAA);

    free(A); free(B); free(RAB); free(RAA);
    printf("Listo. Archivos en mats/\n");
    return 0;
}
