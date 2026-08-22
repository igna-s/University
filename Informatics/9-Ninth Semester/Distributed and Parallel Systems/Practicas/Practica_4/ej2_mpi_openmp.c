#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
#include <float.h>

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

    double *vec = NULL;
    
    if (rank == 0) {
        vec = (double*)malloc(N * sizeof(double));
        for(int i=0; i<N; i++) {
            vec[i] = (double)rand() / RAND_MAX * 1000.0;
        }
    }

    int elements_per_proc = N / size;
    double *vec_local = (double*)malloc(elements_per_proc * sizeof(double));

    MPI_Scatter(vec, elements_per_proc, MPI_DOUBLE, vec_local, elements_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double start_time = MPI_Wtime();

    double local_min = DBL_MAX;
    double local_max = -DBL_MAX;

    #pragma omp parallel
    {
        double t_min = DBL_MAX;
        double t_max = -DBL_MAX;

        #pragma omp for
        for (int i = 0; i < elements_per_proc; i++) {
            if (vec_local[i] < t_min) t_min = vec_local[i];
            if (vec_local[i] > t_max) t_max = vec_local[i];
        }

        #pragma omp critical
        {
            if (t_min < local_min) local_min = t_min;
            if (t_max > local_max) local_max = t_max;
        }
    }

    double end_time = MPI_Wtime();

    double global_min, global_max;
    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Ej2 (MPI+OpenMP): N=%d, Time=%f s, Min=%f, Max=%f\n", N, end_time - start_time, global_min, global_max);
        free(vec);
    }

    free(vec_local);

    MPI_Finalize();
    return 0;
}
