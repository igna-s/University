#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Lee una matriz desde archivo de a datos consecutivos y la almacena en el mismo orden en memoria principal 
double* leerMatriz(double *m, int n, char * fullpath);
// Multiplica, por bloques de BSxBS, dos matrices (a y b) de nxn y deja el resultado en la matriz c
void mmblk_blas(double *a, double *b, double *c, int N, int BS); 
// Valida el resultado. 0 si ok, sino -1. Se valida con error por diferencias de precision con el tipo double
int validar(int n, double *c, char* fileR);
// Para obtener el tiempo de ejecucion
double dwalltime();


int main(int argc, char *argv[]){
 double *a, *b, *c;
 int n, bs;
 double timetick;

  // Chequeo de parametros
  if ( (argc < 6) || ((n = atoi(argv[1])) <= 0) || ((bs = atoi(argv[2])) <= 0) || ((n % bs) != 0))
  {
    printf("\nError en los parametros. Usar: %s N BS (N debe ser multiplo de BS) <ruta y archivo matriz A> <ruta y archivo matriz B> <ruta y archivo matriz resultado> \n", argv[0]);
    exit(1);
  }

	char* fileInA = argv[3];
	char* fileInB = argv[4];
	char* fileInR = argv[5];
	
  // Alocar memoria
  a = (double *) malloc(n*n*sizeof(double));
  b = (double *) malloc(n*n*sizeof(double));
  c = (double *) malloc(n*n*sizeof(double));
  
  // Lee las matrices a y b de archivos. Se almacenan en memoria linealmente tal como se encuentran en archivo
  printf("Leyendo matrices...\n");
  a = leerMatriz(a,n,fileInA); // Asumimos ordenada en archivo por filas, en memoria la utilizamos por filas
  b = leerMatriz(b,n,fileInB); // Asumimos ordenada en archivo por filas, en memoria la utilizamos por filas

  printf("Multiplicando matrices...\n"); 
  timetick = dwalltime();
  // Realiza la multiplicacion	
  mmblk_blas(a, b, c, n, bs);

  double workTime = dwalltime() - timetick;
  

  printf("MMBLK; n:%d ; bs:%d ; Tiempo(seg): %.2lf\n",n,bs,workTime);

    
  // Liberar memoria antes de validar
  free(a);
  free(b);
  
  // Valida
  printf("Validando...\n");
  if (validar(n,c,fileInR) == 0)
	printf("Resultado correcto.\n");
  else
	printf("Error.\n");
  
  // Libera memoria restante
  free(c);

  return 0;
}

double* leerMatriz(double *m, int n, char * fullpath){
	int i, j;
	double val;
	FILE* archivo;

	archivo = fopen(fullpath, "rb");
	if (!archivo) {
		perror("Error al abrir el archivo\n");
		return NULL;
	}

	fread(m, sizeof(double), n * n, archivo);

	fclose(archivo);

	return m;
}

void mmblk_blas(double *a, double *b, double *c, int N, int BS) {
double *ablk, *bblk, *rblk;
int I, J, K;
int i, j, k;
int IN, iN, jBS;
double sum;
double btmp[BS * BS]; // Bloque temporal en stack

    for (I = 0; I < N; I += BS) {
        IN = I * N;
        for (J = 0; J < N; J += BS) {
            rblk = &c[IN + J];     

            // Inicializa bloque de R
            for (i = 0; i < BS; i++) {
                iN = i * N;
                for (j = 0; j < BS; j++)
                    rblk[iN + j] = 0;
            }

            for (K = 0; K < N; K += BS) {
                ablk = &a[IN + K];
                bblk = &b[K * N + J]; // B por filas

                // Reordenar bloque de B por filas en btmp por columnas
                for (i = 0; i < BS; i++) {
					iN = i*N;
                    for (j = 0; j < BS; j++) {
                        btmp[j * BS + i] = bblk[iN + j];
                    }
                }

                // Multiplicación de bloques A por temporal btmp
                for (i = 0; i < BS; i++) {
                    iN = i * N;
                    for (j = 0; j < BS; j++) {
						jBS = j*BS;
                        sum = 0;
                        for (k = 0; k < BS; k++) {
                            sum += ablk[iN + k] * btmp[jBS + k];
                        }
                        rblk[iN + j] += sum;
                    }
                }
            }
        }
    }

}

int validar(int n, double *c, char* fileR) {
 int validacion = 0;
 double* r = (double *) malloc(n*n*sizeof(double));

	leerMatriz(r,n,fileR);

    // Comparar elemento a elemento con cierto margen de error
    double error = 1e-10;  // Tolerancia aceptable para operaciones con double
    for (int i = 0; i < n * n; i++) {
        if (fabs(r[i] - c[i]) > error) {
            validacion = -1;
            printf("Diferencia en elemento %d: r=%.15lf, c=%.15lf, diff=%.3e\n", i, r[i], c[i], fabs(r[i] - c[i]));
        }
    }

    free(r);
    return validacion;
}

/*****************************************************************/

#include <stdio.h>
#include <sys/time.h>

double dwalltime()
{
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}



