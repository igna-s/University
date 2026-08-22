#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

double* leerMatriz(double *m, int n, char *fullpath) {
    FILE* archivo = fopen(fullpath, "rb");
    if (!archivo) return NULL;
    fread(m, sizeof(double), n * n, archivo);
    fclose(archivo);
    return m;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Uso: %s N T <matriz>\n", argv[0]);
        exit(1);
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    char* fileA = argv[3];

    double *A = (double*)malloc(sizeof(double) * N * N);
    leerMatriz(A, N, fileA);

    omp_set_num_threads(T);
    double start_total = dwalltime();

    #pragma omp parallel default(none) shared(A,N)
    {
        int tid = omp_get_thread_num();
        double start_thread = dwalltime();
        
        // Corrected schedule for triangular workload
        #pragma omp for schedule(dynamic)
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N; j++) {
                double temp = A[i*N+j];
                A[i*N+j] = A[j*N+i];
                A[j*N+i] = temp;
            }
        }
        printf("Thread %d terminó en %f segs\n", tid, dwalltime() - start_thread);
    }

    double total_time = dwalltime() - start_total;
    printf("OpenMP Transpose N=%d T=%d Tiempo Total=%f\n", N, T, total_time);

    // Validation: Transpose again should be equal to original
    // (Optional but good)
    
    free(A);
    return 0;
}
