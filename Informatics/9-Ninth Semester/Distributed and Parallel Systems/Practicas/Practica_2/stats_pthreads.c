#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <float.h>

double *A;
int N, T;
double global_min = DBL_MAX;
double global_max = -DBL_MAX;
double global_sum = 0;
pthread_mutex_t mutex;

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

void* stats_worker(void* arg) {
    int tid = *(int*)arg;
    int rpt = (N * N) / T;
    int start = tid * rpt;
    int end = (tid == T - 1) ? (N * N) : (tid + 1) * rpt;

    double local_min = DBL_MAX;
    double local_max = -DBL_MAX;
    double local_sum = 0;

    for (int i = start; i < end; i++) {
        if (A[i] < local_min) local_min = A[i];
        if (A[i] > local_max) local_max = A[i];
        local_sum += A[i];
    }

    pthread_mutex_lock(&mutex);
    if (local_min < global_min) global_min = local_min;
    if (local_max > global_max) global_max = local_max;
    global_sum += local_sum;
    pthread_mutex_unlock(&mutex);

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

    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[T];
    int tids[T];

    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, stats_worker, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double workTime = dwalltime() - timetick;
    double avg = global_sum / (N * N);

    printf("Pthreads Stats N=%d T=%d Tiempo=%f\n", N, T, workTime);
    printf("Min: %f, Max: %f, Avg: %f\n", global_min, global_max, avg);

    free(A);
    pthread_mutex_destroy(&mutex);
    return 0;
}
