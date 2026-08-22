#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

double *A;
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

void* transpose_worker(void* arg) {
    int tid = *(int*)arg;
    
    // Interleaved rows for better balance in triangular workload
    for (int i = tid; i < N; i += T) {
        for (int j = i + 1; j < N; j++) {
            double temp = A[i * N + j];
            A[i * N + j] = A[j * N + i];
            A[j * N + i] = temp;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Uso: %s N T <matriz>\n", argv[0]);
        exit(1);
    }

    N = atoi(argv[1]);
    T = atoi(argv[2]);
    char* fileA = argv[3];

    A = (double*)malloc(sizeof(double) * N * N);
    leerMatriz(A, N, fileA);

    pthread_t threads[T];
    int tids[T];

    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, transpose_worker, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double workTime = dwalltime() - timetick;
    printf("Pthreads Transpose N=%d T=%d Tiempo=%f\n", N, T, workTime);

    free(A);
    return 0;
}
