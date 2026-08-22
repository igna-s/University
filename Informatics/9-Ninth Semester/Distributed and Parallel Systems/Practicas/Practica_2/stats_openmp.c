#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <float.h>

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

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Uso: %s N T <matriz>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    char* fileA = argv[3];

    double *A = (double*)malloc(sizeof(double) * N * N);
    leerMatriz(A, N, fileA);

    double min_val = DBL_MAX;
    double max_val = -DBL_MAX;
    double sum_val = 0;

    omp_set_num_threads(T);
    double timetick = dwalltime();

    #pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+:sum_val)
    for (int i = 0; i < N * N; i++) {
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
        sum_val += A[i];
    }

    double workTime = dwalltime() - timetick;
    double avg = sum_val / (N * N);

    printf("OpenMP Stats N=%d T=%d Tiempo=%f\n", N, T, workTime);
    printf("Min: %f, Max: %f, Avg: %f\n", min_val, max_val, avg);

    free(A);
    return 0;
}
