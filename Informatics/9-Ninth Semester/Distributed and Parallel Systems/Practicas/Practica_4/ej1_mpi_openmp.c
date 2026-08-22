#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int rank, size, N, num_threads;
    
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

    omp_set_num_threads(num_threads);

    double *A = NULL;
    double *C = NULL;

    double *B = (double*)malloc(N * N * sizeof(double));

    if (rank == 0) {
        A = (double*)malloc(N * N * sizeof(double));
        C = (double*)malloc(N * N * sizeof(double));
        
        // Inicializar
        for(int i=0; i<N*N; i++) {
            A[i] = 1.0;
            B[i] = 2.0;
        }
    }

    MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    int rows_per_proc = N / size;
    double *A_local = (double*)malloc(rows_per_proc * N * sizeof(double));
    double *C_local = (double*)malloc(rows_per_proc * N * sizeof(double));

    MPI_Scatter(A, rows_per_proc * N, MPI_DOUBLE, A_local, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    #pragma omp parallel for
    for (int i = 0; i < rows_per_proc; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A_local[i * N + k] * B[k * N + j];
            }
            C_local[i * N + j] = sum;
        }
    }

    double end_time = MPI_Wtime();

    MPI_Gather(C_local, rows_per_proc * N, MPI_DOUBLE, C, rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Ej1 (MPI+OpenMP): N=%d, Time=%f s\n", N, end_time - start_time);
        free(A);
        free(C);
    }

    free(A_local);
    free(C_local);
    free(B);

    MPI_Finalize();
    return 0;
}
