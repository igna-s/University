#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__device__ bool is_safe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

__global__ void solve_nqueens_cuda(int N, unsigned long long *d_solutions) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    
    // Generar un estado inicial basado en idx
    // Para simplificar, distribuimos la primera fila entre los hilos
    if (idx >= N) return;
    
    int board[20]; // asumiendo N <= 20
    board[0] = idx;
    
    int row = 1;
    unsigned long long local_solutions = 0;
    
    board[row] = -1;
    
    while (row > 0) {
        board[row]++;
        
        while (board[row] < N && !is_safe(board, row, board[row])) {
            board[row]++;
        }
        
        if (board[row] < N) {
            if (row == N - 1) {
                local_solutions++;
                // no avanzamos de fila porque terminamos, probamos el siguiente col
            } else {
                row++;
                board[row] = -1;
            }
        } else {
            row--;
        }
    }
    
    atomicAdd(d_solutions, local_solutions);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    
    unsigned long long h_solutions = 0;
    unsigned long long *d_solutions;
    
    cudaMalloc((void**)&d_solutions, sizeof(unsigned long long));
    cudaMemcpy(d_solutions, &h_solutions, sizeof(unsigned long long), cudaMemcpyHostToDevice);
    
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    
    cudaEventRecord(start);
    
    // Usaremos un hilo por posible valor de la primera fila. 
    // Para mayor paralelismo se deberia distribuir hasta la fila 2 o 3.
    // Esto es un prototipo pedido en la practica.
    int threads_per_block = N;
    if (threads_per_block > 1024) threads_per_block = 1024;
    int blocks = (N + threads_per_block - 1) / threads_per_block;
    
    solve_nqueens_cuda<<<blocks, threads_per_block>>>(N, d_solutions);
    
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    
    cudaMemcpy(&h_solutions, d_solutions, sizeof(unsigned long long), cudaMemcpyDeviceToHost);
    
    printf("Ej6 (N-Reinas CUDA): N=%d, Soluciones=%llu, Tiempo=%f ms\n", N, h_solutions, milliseconds);
    
    cudaFree(d_solutions);
    return 0;
}
