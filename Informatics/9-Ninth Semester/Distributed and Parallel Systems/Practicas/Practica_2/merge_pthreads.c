#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

double *arr, *temp;
int N, T;
pthread_barrier_t barrier;

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

// Sequential mergesort for chunks
void merge_seq(double *a, double *tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < right) tmp[k++] = a[j++];
    for (i = left; i < right; i++) a[i] = tmp[i];
}

void mergesort_seq(double *a, double *tmp, int left, int right) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;
    mergesort_seq(a, tmp, left, mid);
    mergesort_seq(a, tmp, mid, right);
    merge_seq(a, tmp, left, mid, right);
}

void* merge_worker(void* arg) {
    int tid = *(int*)arg;
    int chunk_size = N / T;
    int left = tid * chunk_size;
    int right = (tid == T - 1) ? N : (tid + 1) * chunk_size;

    // Stage 0: Sort local chunk
    mergesort_seq(arr, temp, left, right);

    // Stage 1 to log2(T): Merge stages
    int stride = 1;
    while (stride < T) {
        pthread_barrier_wait(&barrier);
        if (tid % (2 * stride) == 0) {
            int neighbor = tid + stride;
            if (neighbor < T) {
                int mid = neighbor * chunk_size;
                int end = (neighbor + stride >= T) ? N : (neighbor + stride) * chunk_size;
                merge_seq(arr, temp, left, mid, end);
            }
        }
        stride *= 2;
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s N T\n", argv[0]);
        exit(1);
    }
    N = atoi(argv[1]);
    T = atoi(argv[2]);

    arr = (double*)malloc(sizeof(double) * N);
    temp = (double*)malloc(sizeof(double) * N);

    // Initialize with random data
    for (int i = 0; i < N; i++) arr[i] = (double)rand() / RAND_MAX;

    pthread_barrier_init(&barrier, NULL, T);
    pthread_t threads[T];
    int tids[T];

    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, merge_worker, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double total_time = dwalltime() - timetick;
    printf("Pthreads MergeSort N=%d T=%d Tiempo=%f\n", N, T, total_time);

    // Verify sort
    int ok = 1;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] > arr[i + 1]) { ok = 0; break; }
    }
    printf("Validacion %s\n", ok ? "OK" : "ERROR");

    free(arr); free(temp);
    pthread_barrier_destroy(&barrier);
    return 0;
}
