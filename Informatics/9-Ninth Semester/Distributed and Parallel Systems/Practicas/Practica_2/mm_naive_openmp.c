#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <string.h>

double* leerMatriz(double *m, int n, char *fullpath) {
    FILE* archivo = fopen(fullpath, "rb");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return NULL;
    }
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
    if (argc < 6) {
        printf("Uso: %s N T <matrizA> <matrizB> <matrizR>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    char* fileA = argv[3];
    char* fileB = argv[4];
    char* fileR = argv[5];

    double *A = (double*)malloc(sizeof(double) * N * N);
    double *B = (double*)malloc(sizeof(double) * N * N);
    double *C = (double*)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);
    leerMatriz(B, N, fileB);

    omp_set_num_threads(T);

    double timetick = dwalltime();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }

    double workTime = dwalltime() - timetick;
    printf("OpenMP mm_naive N=%d T=%d Tiempo=%f\n", N, T, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(B); free(C);
    return 0;
}
