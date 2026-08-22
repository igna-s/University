#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <string.h>

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
    int res = memcmp(r, c, n * n * sizeof(double));
    free(r);
    return res == 0 ? 0 : -1;
}

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Uso: %s N T <matrizA> <matrizR>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    char* fileA = argv[3];
    char* fileR = argv[4];

    double *A = (double*)malloc(sizeof(double) * N * N);
    double *Acol = (double*)malloc(sizeof(double) * N * N);
    double *C = (double*)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);
    omp_set_num_threads(T);

    double timetick = dwalltime();

    // Stage 1: Transpose A to Acol
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Acol[j * N + i] = A[i * N + j];
        }
    }

    // Stage 2: Multiply
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * Acol[j * N + k];
            }
            C[i * N + j] = sum;
        }
    }

    double workTime = dwalltime() - timetick;
    printf("OpenMP mm_sq N=%d T=%d Tiempo=%f\n", N, T, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(Acol); free(C);
    return 0;
}
