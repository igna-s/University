#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>
#include <stdbool.h>
#include <sys/time.h>

bool is_safe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve_nqueens(int board[], int row, int n, long long *solutions) {
    if (row == n) {
        (*solutions)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col)) {
            board[row] = col;
            solve_nqueens(board, row + 1, n, solutions);
        }
    }
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

    int N = atoi(argv[1]);
    int num_threads = atoi(argv[2]);
    omp_set_num_threads(num_threads);

    double start_time = MPI_Wtime();
    long long local_solutions = 0;

    // Distribute the first row placement across MPI processes
    // and then use OpenMP inside each process.
    #pragma omp parallel for reduction(+:local_solutions) schedule(dynamic)
    for (int i = rank; i < N; i += size) {
        int *board = (int*)malloc(N * sizeof(int));
        board[0] = i;
        long long thread_solutions = 0;
        solve_nqueens(board, 1, N, &thread_solutions);
        local_solutions += thread_solutions;
        free(board);
    }

    double end_time = MPI_Wtime();

    long long global_solutions = 0;
    MPI_Reduce(&local_solutions, &global_solutions, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Ej3 (N-Reinas MPI+OpenMP): N=%d, Soluciones=%lld, Tiempo=%f s\n", N, global_solutions, end_time - start_time);
    }

    MPI_Finalize();
    return 0;
}
