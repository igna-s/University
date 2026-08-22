#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <pthread.h>
#include <float.h>

int elements_per_proc;
int num_threads;
double *vec_local;
double local_min;
double local_max;
pthread_mutex_t mutex;

void* thread_minmax(void* arg) {
    long thread_id = (long)arg;
    int elements_per_thread = elements_per_proc / num_threads;
    int start_idx = thread_id * elements_per_thread;
    int end_idx = (thread_id == num_threads - 1) ? elements_per_proc : start_idx + elements_per_thread;

    double t_min = DBL_MAX;
    double t_max = -DBL_MAX;

    for (int i = start_idx; i < end_idx; i++) {
        if (vec_local[i] < t_min) t_min = vec_local[i];
        if (vec_local[i] > t_max) t_max = vec_local[i];
    }

    pthread_mutex_lock(&mutex);
    if (t_min < local_min) local_min = t_min;
    if (t_max > local_max) local_max = t_max;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    int rank, size, N;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 3) {
        if (rank == 0) printf("Uso: %s <N> <num_threads>\n", argv[0]);
        MPI_Finalize();
        return 1;
    }

    N = atoi(argv[1]);
    num_threads = atoi(argv[2]);

    double *vec = NULL;
    
    if (rank == 0) {
        vec = (double*)malloc(N * sizeof(double));
        for(int i=0; i<N; i++) {
            vec[i] = (double)rand() / RAND_MAX * 1000.0;
        }
    }

    elements_per_proc = N / size;
    vec_local = (double*)malloc(elements_per_proc * sizeof(double));

    MPI_Scatter(vec, elements_per_proc, MPI_DOUBLE, vec_local, elements_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    local_min = DBL_MAX;
    local_max = -DBL_MAX;
    pthread_mutex_init(&mutex, NULL);

    pthread_t *threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    for (long t = 0; t < num_threads; t++) {
        pthread_create(&threads[t], NULL, thread_minmax, (void*)t);
    }
    for (int t = 0; t < num_threads; t++) {
        pthread_join(threads[t], NULL);
    }

    double end_time = MPI_Wtime();

    double global_min, global_max;
    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Ej2 (MPI+Pthreads): N=%d, Time=%f s, Min=%f, Max=%f\n", N, end_time - start_time, global_min, global_max);
        free(vec);
    }

    free(vec_local);
    free(threads);
    pthread_mutex_destroy(&mutex);

    MPI_Finalize();
    return 0;
}
