#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

double *A, *Acol, *C;
int N, T;

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
    int res = memcmp(r, c, n * n * sizeof(double));
    free(r);
    return res == 0 ? 0 : -1;
}

pthread_barrier_t barrier;

void* worker_sq(void* arg) {
    int tid = *(int*)arg;
    int i, j, k;
    int rpt = N / T;
    int start = tid * rpt;
    int end = (tid == T - 1) ? N : (tid + 1) * rpt;

    // Stage 1: Reorganize A to Acol (Column-major)
    for (i = start; i < end; i++) {
        for (j = 0; j < N; j++) {
            Acol[j * N + i] = A[i * N + j];
        }
    }

    pthread_barrier_wait(&barrier);

    // Stage 2: Multiply A(row) * Acol(col)
    for (i = start; i < end; i++) {
        for (j = 0; j < N; j++) {
            double sum = 0;
            for (k = 0; k < N; k++) {
                sum += A[i * N + k] * Acol[j * N + k];
            }
            C[i * N + j] = sum;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Uso: %s N T <matrizA> <matrizR>\n", argv[0]);
        exit(1);
    }

    N = atoi(argv[1]);
    T = atoi(argv[2]);
    char* fileA = argv[3];
    char* fileR = argv[4];

    A = (double*)malloc(sizeof(double) * N * N);
    Acol = (double*)malloc(sizeof(double) * N * N);
    C = (double*)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);
    pthread_barrier_init(&barrier, NULL, T);

    pthread_t threads[T];
    int tids[T];
    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, worker_sq, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double workTime = dwalltime() - timetick;
    printf("Pthreads mm_sq N=%d T=%d Tiempo=%f\n", N, T, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(Acol); free(C);
    pthread_barrier_destroy(&barrier);
    return 0;
}
