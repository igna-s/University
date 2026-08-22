#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <pthread.h>
#include <sys/time.h>

int N;
int num_threads;
double *A_local;
double *B;
double *C_local;
int rows_per_proc;

void* thread_matmul(void* arg) {
    long thread_id = (long)arg;
    int rows_per_thread = rows_per_proc / num_threads;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id == num_threads - 1) ? rows_per_proc : start_row + rows_per_thread;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A_local[i * N + k] * B[k * N + j];
            }
            C_local[i * N + j] = sum;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int rank, size;
    
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

    double *A = NULL;
    double *C = NULL;

    B = (double*)malloc(N * N * sizeof(double));

    if (rank == 0) {
        A = (double*)malloc(N * N * sizeof(double));
        C = (double*)malloc(N * N * sizeof(double));
        
        // Inicializar
        for(int i=0; i<N*N; i++) {
            A[i] = 1.0;
            B[i] = 2.0;
        }
    }

    // Distribuir B a todos
    MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    rows_per_proc = N / size;
    A_local = (double*)malloc(rows_per_proc * N * sizeof(double));
    C_local = (double*)malloc(rows_per_proc * N * sizeof(double));

    MPI_Scatter(A, rows_per_proc * N, MPI_DOUBLE, A_local, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    pthread_t *threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    for (long t = 0; t < num_threads; t++) {
        pthread_create(&threads[t], NULL, thread_matmul, (void*)t);
    }
    for (int t = 0; t < num_threads; t++) {
        pthread_join(threads[t], NULL);
    }

    double end_time = MPI_Wtime();

    MPI_Gather(C_local, rows_per_proc * N, MPI_DOUBLE, C, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Ej1 (MPI+Pthreads): N=%d, Time=%f s\n", N, end_time - start_time);
        free(A);
        free(C);
    }

    free(A_local);
    free(C_local);
    free(B);
    free(threads);

    MPI_Finalize();
    return 0;
}
