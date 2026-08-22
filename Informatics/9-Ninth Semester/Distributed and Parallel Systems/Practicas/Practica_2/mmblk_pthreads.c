#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>

double *A, *B, *C;
int N, T, BS;

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

int validar(int n, double *c, char* fileR) {
    double* r = (double *) malloc(n * n * sizeof(double));
    leerMatriz(r, n, fileR);
    int ok = 1;
    for (int i = 0; i < n * n; i++) {
        if (fabs(c[i] - r[i]) > 1e-6 * fabs(r[i]) + 1e-10) { ok = 0; break; }
    }
    free(r);
    return ok ? 0 : -1;
}

void blkmul(double *ablk, double *bblk, double *cblk, int n, int bs) {
    int i, j, k;
    for (i = 0; i < bs; i++) {
        for (j = 0; j < bs; j++) {
            double sum = 0;
            for (k = 0; k < bs; k++) {
                sum += ablk[i * n + k] * bblk[j * n + k];
            }
            cblk[i * n + j] += sum;
        }
    }
}

void* matmulblks_pthreads(void* arg) {
    int tid = *(int*)arg;
    int i, j, k;
    
    // Foster: Partition by rows of blocks
    int num_blocks = N / BS;
    int blocks_per_thread = num_blocks / T;
    int start_block_row = tid * blocks_per_thread;
    int end_block_row = (tid == T - 1) ? num_blocks : (tid + 1) * blocks_per_thread;

    for (i = start_block_row; i < end_block_row; i++) {
        int iN = i * BS * N;
        for (j = 0; j < num_blocks; j++) {
            int jN = j * BS * N;
            int iNj = iN + j * BS;
            for (k = 0; k < num_blocks; k++) {
                blkmul(&A[iN + k * BS], &B[jN + k * BS], &C[iNj], N, BS);
            }
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 7) {
        printf("Uso: %s N T BS <matA> <matBcol> <matR>\n", argv[0]);
        exit(1);
    }

    N = atoi(argv[1]);
    T = atoi(argv[2]);
    BS = atoi(argv[3]);
    char* fileA = argv[4];
    char* fileB = argv[5];
    char* fileR = argv[6];

    A = (double*)malloc(sizeof(double) * N * N);
    B = (double*)malloc(sizeof(double) * N * N);
    C = (double*)calloc(N * N, sizeof(double));

    leerMatriz(A, N, fileA);
    leerMatriz(B, N, fileB);

    pthread_t threads[T];
    int tids[T];
    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, matmulblks_pthreads, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double workTime = dwalltime() - timetick;
    printf("Pthreads mmblk N=%d T=%d BS=%d Tiempo=%f\n", N, T, BS, workTime);

    if (validar(N, C, fileR) == 0) printf("Validacion OK\n");
    else printf("Validacion ERROR\n");

    free(A); free(B); free(C);
    return 0;
}
