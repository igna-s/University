#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <math.h>

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

double* leerMatriz(double *m, int n, char *fullpath) {
    FILE* archivo = fopen(fullpath, "rb");
    if (!archivo) return NULL;
    fread(m, sizeof(double), n * n, archivo);
    fclose(archivo);
    return m;
}

int validar(int n, double *c, char* fileR) {
    double* r = (double *) malloc(n * n * sizeof(double));
    leerMatriz(r, n, fileR);
    int ok = 1;
    for (int i = 0; i < n * n; i++) {
        if (fabs(c[i] - r[i]) > 1e-6 * fabs(r[i]) + 1e-10) { ok = 0; break; }
    }
    free(r);
    return ok ? 0 : -1;
}

int main(int argc, char* argv[]) {
    if (argc < 7) {
        printf("Uso: %s N T BS <matA> <matB> <matR>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    int BS = atoi(argv[3]);
    char* fileA = argv[4];
    char* fileB = argv[5];
    char* fileR = argv[6];

    double *A = (double*)malloc(sizeof(double) * N * N);
    double *B = (double*)malloc(sizeof(double) * N * N);
    double *C = (double*)calloc(N * N, sizeof(double));

    leerMatriz(A, N, fileA);
    leerMatriz(B, N, fileB);

    omp_set_num_threads(T);
    int num_blocks = N / BS;

    double timetick = dwalltime();

    #pragma omp parallel for collapse(2) schedule(static)
    for (int I = 0; I < num_blocks; I++) {
        for (int J = 0; J < num_blocks; J++) {
            int IN = I * BS * N;
            int JBS = J * BS;
            double *rblk = &C[IN + JBS];
            double btmp[BS * BS];

            /* Inicializar bloque resultado */
            for (int i = 0; i < BS; i++)
                for (int j = 0; j < BS; j++)
                    rblk[i * N + j] = 0.0;

            for (int K = 0; K < num_blocks; K++) {
                double *ablk = &A[IN + K * BS];
                double *bblk = &B[K * BS * N + JBS];

                /* Reordenar bloque de B a column-major en btmp (local, privado por iteracion) */
                for (int i = 0; i < BS; i++)
                    for (int j = 0; j < BS; j++)
                        btmp[j * BS + i] = bblk[i * N + j];

                /* Multiplicar bloque A por btmp */
                for (int i = 0; i < BS; i++) {
                    int iN = i * N;
                    for (int j = 0; j < BS; j++) {
                        double sum = 0;
                        int jBS = j * BS;
                        for (int k = 0; k < BS; k++)
                            sum += ablk[iN + k] * btmp[jBS + k];
                        rblk[iN + j] += sum;
                    }
                }
            }
        }
    }

    double workTime = dwalltime() - timetick;
    printf("OpenMP mmblk_blas N=%d T=%d BS=%d Tiempo=%f\n", N, T, BS, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(B); free(C);
    return 0;
}
