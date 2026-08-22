#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

// Shared variables (PDF requirement: not passed as parameters)
double *A, *B, *C;
int N, T;

// Helper to get timing
double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

// Matrix reading
double* leerMatriz(double *m, int n, char *fullpath) {
    FILE* archivo = fopen(fullpath, "rb");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return NULL;
    }
    fread(m, sizeof(double), n * n, archivo);
    fclose(archivo);
    return m;
}

// Validation
int validar(int n, double *c, char* fileR) {
    double* r = (double *) malloc(n * n * sizeof(double));
    leerMatriz(r, n, fileR);
    int res = memcmp(r, c, n * n * sizeof(double));
    free(r);
    return res == 0 ? 0 : -1;
}

// Thread function
void* matmul_pthreads(void* arg) {
    int tid = *(int*)arg;
    int i, j, k;
    
    // Foster design: Division by rows
    int rows_per_thread = N / T;
    int start_row = tid * rows_per_thread;
    int end_row = (tid == T - 1) ? N : (tid + 1) * rows_per_thread;

    for (i = start_row; i < end_row; i++) {
        for (j = 0; j < N; j++) {
            double sum = 0;
            for (k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        printf("Uso: %s N T <matrizA> <matrizB> <matrizR>\n", argv[0]);
        exit(1);
    }

    N = atoi(argv[1]);
    T = atoi(argv[2]);
    char* fileA = argv[3];
    char* fileB = argv[4];
    char* fileR = argv[5];

    A = (double*)malloc(sizeof(double) * N * N);
    B = (double*)malloc(sizeof(double) * N * N);
    C = (double*)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);
    leerMatriz(B, N, fileB);

    pthread_t threads[T];
    int tids[T];
    
    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, matmul_pthreads, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double workTime = dwalltime() - timetick;
    printf("Pthreads mm_naive N=%d T=%d Tiempo=%f\n", N, T, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(B); free(C);
    return 0;
}
