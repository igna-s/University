#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__global__ void reduceSum(double *d_in, double *d_out, int N) {
    extern __shared__ double sdata[];

    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x * (blockDim.x * 2) + threadIdx.x;

    // Load elements into shared memory and perform first level of reduction
    double mySum = (i < N) ? d_in[i] : 0.0;
    if (i + blockDim.x < N) {
        mySum += d_in[i + blockDim.x];
    }
    sdata[tid] = mySum;
    __syncthreads();

    // Do reduction in shared memory
    for (unsigned int s = blockDim.x / 2; s > 0; s >>= 1) {
        if (tid < s) {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    // Write result for this block to global memory
    if (tid == 0) {
        d_out[blockIdx.x] = sdata[0];
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <threads_per_block>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int threads_per_block = atoi(argv[2]); // 256 o 512

    size_t size = N * sizeof(double);
    
    double *h_in = (double*)malloc(size);
    for (int i = 0; i < N; i++) {
        h_in[i] = (double)(i % 100); // Valores de prueba
    }
    
    double *d_in, *d_out;
    cudaMalloc((void**)&d_in, size);
    
    // El número de bloques inicial es (N + threads_per_block*2 - 1) / (threads_per_block*2)
    int num_blocks = (N + (threads_per_block * 2) - 1) / (threads_per_block * 2);
    cudaMalloc((void**)&d_out, num_blocks * sizeof(double));
    
    cudaMemcpy(d_in, h_in, size, cudaMemcpyHostToDevice);
    
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    
    cudaEventRecord(start);
    
    // Iterative reduction if we have more than 1 block
    int current_N = N;
    int current_blocks = num_blocks;
    
    reduceSum<<<current_blocks, threads_per_block, threads_per_block * sizeof(double)>>>(d_in, d_out, current_N);
    
    // Copy result back to host to finish reduction (or continue on device, but for simplicity we do it on host)
    double *h_out = (double*)malloc(current_blocks * sizeof(double));
    cudaMemcpy(h_out, d_out, current_blocks * sizeof(double), cudaMemcpyDeviceToHost);
    
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    
    double total_sum = 0;
    for (int i = 0; i < current_blocks; i++) {
        total_sum += h_out[i];
    }
    
    double average = total_sum / N;
    
    printf("Ej5 (CUDA): N=%d, TPB=%d, Time=%f ms, Avg=%f\n", N, threads_per_block, milliseconds, average);
    
    cudaFree(d_in);
    cudaFree(d_out);
    free(h_in);
    free(h_out);
    
    return 0;
}
