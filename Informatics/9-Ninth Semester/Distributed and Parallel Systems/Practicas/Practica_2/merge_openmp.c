#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>
#include <string.h>

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

void merge(double *a, double *tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < right) tmp[k++] = a[j++];
    for (i = left; i < right; i++) a[i] = tmp[i];
}

void mergesort_rec(double *a, double *tmp, int left, int right, int depth) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;

    if (depth > 0) {
        #pragma omp task shared(a, tmp)
        mergesort_rec(a, tmp, left, mid, depth - 1);
        
        #pragma omp task shared(a, tmp)
        mergesort_rec(a, tmp, mid, right, depth - 1);
        
        #pragma omp taskwait
    } else {
        mergesort_rec(a, tmp, left, mid, 0);
        mergesort_rec(a, tmp, mid, right, 0);
    }
    merge(a, tmp, left, mid, right);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s N T\n", argv[0]);
        exit(1);
    }
    int N = atoi(argv[1]);
    int T = atoi(argv[2]);

    double *arr = (double*)malloc(sizeof(double) * N);
    double *temp = (double*)malloc(sizeof(double) * N);

    for (int i = 0; i < N; i++) arr[i] = (double)rand() / RAND_MAX;

    omp_set_num_threads(T);
    double timetick = dwalltime();

    #pragma omp parallel
    {
        #pragma omp single
        mergesort_rec(arr, temp, 0, N, 4); // Limit depth to avoid too many tasks
    }

    double total_time = dwalltime() - timetick;
    printf("OpenMP MergeSort N=%d T=%d Tiempo=%f\n", N, T, total_time);

    int ok = 1;
    for (int i = 0; i < N - 1; i++) {
        if (arr[i] > arr[i + 1]) { ok = 0; break; }
    }
    printf("Validacion %s\n", ok ? "OK" : "ERROR");

    free(arr); free(temp);
    return 0;
}
