#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void mu_naive(double *A, double *U, double *C, int N);
void mu_optimized(double *A, double *U, double *C, int N);
void ml_naive(double *A, double *L, double *C, int N);
void ml_optimized(double *A, double *L, double *C, int N);
void um_naive(double *U, double *A, double *C, int N);
void um_optimized(double *U, double *A, double *C, int N);
void lm_naive(double *L, double *A, double *C, int N);
void lm_optimized(double *L, double *A, double *C, int N);

double* leerMatriz(double *m, int n, char *fullpath);
double dwalltime(void);

int main(int argc, char *argv[]) {
    int N;
    if ((argc < 3) || ((N = atoi(argv[1])) <= 0)) {
        printf("\nError en los parametros. Usar: %s N <archivo A>\n", argv[0]);
        exit(1);
    }

    char *fileA = argv[2];
    double *A = (double *)malloc(sizeof(double) * N * N);
    double *T = (double *)malloc(sizeof(double) * N * N);
    double *C = (double *)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);

    // MU (Matrix * Upper)
    memset(T, 0, sizeof(double) * N * N);
    for(int i=0; i<N; i++) for(int j=i; j<N; j++) T[i*N+j] = A[i*N+j]; // Make A Upper
    
    double t1 = dwalltime();
    mu_naive(A, T, C, N);
    double d1 = dwalltime() - t1;
    
    double t2 = dwalltime();
    mu_optimized(A, T, C, N);
    double d2 = dwalltime() - t2;
    printf("MU - Naive: %f, Optimized: %f\n", d1, d2);

    // ML (Matrix * Lower)
    memset(T, 0, sizeof(double) * N * N);
    for(int i=0; i<N; i++) for(int j=0; j<=i; j++) T[i*N+j] = A[i*N+j]; // Make A Lower
    
    t1 = dwalltime();
    ml_naive(A, T, C, N);
    d1 = dwalltime() - t1;
    
    t2 = dwalltime();
    ml_optimized(A, T, C, N);
    d2 = dwalltime() - t2;
    printf("ML - Naive: %f, Optimized: %f\n", d1, d2);

    // UM (Upper * Matrix)
    memset(T, 0, sizeof(double) * N * N);
    for(int i=0; i<N; i++) for(int j=i; j<N; j++) T[i*N+j] = A[i*N+j]; // Make A Upper
    
    t1 = dwalltime();
    um_naive(T, A, C, N);
    d1 = dwalltime() - t1;
    
    t2 = dwalltime();
    um_optimized(T, A, C, N);
    d2 = dwalltime() - t2;
    printf("UM - Naive: %f, Optimized: %f\n", d1, d2);

    // LM (Lower * Matrix)
    memset(T, 0, sizeof(double) * N * N);
    for(int i=0; i<N; i++) for(int j=0; j<=i; j++) T[i*N+j] = A[i*N+j]; // Make A Lower
    
    t1 = dwalltime();
    lm_naive(T, A, C, N);
    d1 = dwalltime() - t1;
    
    t2 = dwalltime();
    lm_optimized(T, A, C, N);
    d2 = dwalltime() - t2;
    printf("LM - Naive: %f, Optimized: %f\n", d1, d2);

    free(A);
    free(T);
    free(C);
    return 0;
}

// Implementations
void mu_naive(double *A, double *U, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<N; k++) C[i*N+j] += A[i*N+k] * U[k*N+j];
    }
}
void mu_optimized(double *A, double *U, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<=j; k++) C[i*N+j] += A[i*N+k] * U[k*N+j];
    }
}

void ml_naive(double *A, double *L, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<N; k++) C[i*N+j] += A[i*N+k] * L[k*N+j];
    }
}
void ml_optimized(double *A, double *L, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=j; k<N; k++) C[i*N+j] += A[i*N+k] * L[k*N+j];
    }
}

void um_naive(double *U, double *A, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<N; k++) C[i*N+j] += U[i*N+k] * A[k*N+j];
    }
}
void um_optimized(double *U, double *A, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=i; k<N; k++) C[i*N+j] += U[i*N+k] * A[k*N+j];
    }
}

void lm_naive(double *L, double *A, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<N; k++) C[i*N+j] += L[i*N+k] * A[k*N+j];
    }
}
void lm_optimized(double *L, double *A, double *C, int N) {
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        C[i*N+j] = 0;
        for(int k=0; k<=i; k++) C[i*N+j] += L[i*N+k] * A[k*N+j];
    }
}

double* leerMatriz(double *m, int n, char *fullpath) {
    FILE *archivo = fopen(fullpath, "rb");
    if (!archivo) return NULL;
    fread(m, sizeof(double), n * n, archivo);
    fclose(archivo);
    return m;
}

double dwalltime(void) {
    double sec; struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}
