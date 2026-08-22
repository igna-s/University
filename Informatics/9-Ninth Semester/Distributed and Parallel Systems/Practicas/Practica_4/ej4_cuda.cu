#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__global__ void matrixAdd(double *A, double *B, double *C, int N) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < N && col < N) {
        int idx = row * N + col;
        C[idx] = A[idx] + B[idx];
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <threads_per_block>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int threads_per_block = atoi(argv[2]); // 256 o 512
    
    int dim = (int)sqrt((double)threads_per_block); // por ejemplo 16x16=256

    size_t size = N * N * sizeof(double);
    
    double *h_A = (double*)malloc(size);
    double *h_B = (double*)malloc(size);
    double *h_C = (double*)malloc(size);
    
    for (int i = 0; i < N * N; i++) {
        h_A[i] = 1.0;
        h_B[i] = 2.0;
    }
    
    double *d_A, *d_B, *d_C;
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_C, size);
    
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
    
    dim3 threads(dim, dim);
    dim3 blocks((N + dim - 1) / dim, (N + dim - 1) / dim);
    
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    
    cudaEventRecord(start);
    matrixAdd<<<blocks, threads>>>(d_A, d_B, d_C, N);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    
    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    
    printf("Ej4 (CUDA): N=%d, TPB=%d, Time=%f ms\n", N, threads_per_block, milliseconds);
    
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    free(h_A);
    free(h_B);
    free(h_C);
    
    return 0;
}
