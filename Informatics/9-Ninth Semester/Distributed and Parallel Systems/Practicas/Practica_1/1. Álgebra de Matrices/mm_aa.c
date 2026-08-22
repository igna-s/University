#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void matmul_row(double *A, double *C, int N);
void matmul_reorder(double *A, double *C, int N);
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
    double *C1 = (double *)malloc(sizeof(double) * N * N);
    double *C2 = (double *)malloc(sizeof(double) * N * N);

    leerMatriz(A, N, fileA);

    printf("Calculando C=A*A con ambas por filas...\n");
    double timetick = dwalltime();
    matmul_row(A, C1, N);
    double time1 = dwalltime() - timetick;
    printf("Estrategia 1 (Row-Row) Tiempo en segundos: %f\n", time1);

    printf("Calculando C=A*A con derecha reordenada por columnas...\n");
    timetick = dwalltime();
    matmul_reorder(A, C2, N);
    double time2 = dwalltime() - timetick;
    printf("Estrategia 2 (Row-Col) Tiempo en segundos: %f\n", time2);

    // Comparación básica de resultados
    if (memcmp(C1, C2, sizeof(double) * N * N) == 0) {
        printf("Resultados coinciden.\n");
    } else {
        printf("Error: Resultados no coinciden.\n");
    }

    free(A);
    free(C1);
    free(C2);
    return 0;
}

void matmul_row(double *A, double *C, int N) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] = 0;
            for (k = 0; k < N; k++) {
                C[i * N + j] += A[i * N + k] * A[k * N + j];
            }
        }
    }
}

void matmul_reorder(double *A, double *C, int N) {
    int i, j, k;
    double *At = (double *)malloc(sizeof(double) * N * N);

    // Reordenar A a column-major
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            At[j * N + i] = A[i * N + j];
        }
    }

    // Multiplicar
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i * N + j] = 0;
            for (k = 0; k < N; k++) {
                // A es row-major, At es column-major
                C[i * N + j] += A[i * N + k] * At[j * N + k];
            }
        }
    }

    free(At);
}

double* leerMatriz(double *m, int n, char *fullpath) {
    FILE *archivo = fopen(fullpath, "rb");
    if (!archivo) {
        perror("Error al abrir el archivo\n");
        return NULL;
    }
    fread(m, sizeof(double), n * n, archivo);
    fclose(archivo);
    return m;
}

double dwalltime(void) {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}
