#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>

// Lee una matriz desde archivo de a datos consecutivos y la almacena en el mismo orden en memoria principal 
double* leerMatriz(double *m, int n, char * fullpath);
// Multiplica, por bloques de bsxbs, dos matrices (a y b) de nxn y deja el resultado en la matriz c
void matmulblks(double *a, double *b, double *c, int n, int bs);
void blkmul(double *ablk, double *bblk, double *cblk, int n, int bs);
// Valida el resultado 0 si ok, sino -1
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
  b = leerMatriz(b,n,fileInB); // Asumimos ordenada en archivo por columnas, en memoria la utilizamos por columnas

  printf("Multiplicando matrices...\n"); 
  timetick = dwalltime();
  // Realiza la multiplicacion	
  matmulblks(a, b, c, n, bs);

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

void matmulblks(double *a, double *b, double *c, int N, int bs){
int i, j, k;
int iN, jN, iNj;

    // Inicializa la matriz resultado
	for (i = 0; i < N*N; i++){
		c[i] = 0;
	}
  
    // Multiplica
	for (i = 0; i < N; i += bs){
		iN = i*N;
		for (j = 0; j < N; j += bs){
			jN = j*N;
			iNj = iN + j;
			for  (k = 0; k < N; k += bs){
				blkmul(&a[iN + k], &b[jN + k], &c[iNj], N, bs);
			}
			
		}
	}

}

void blkmul(double *ablk, double *bblk, double *cblk, int N, int bs){
 int i, j, k;
 int iN, jN, iNj;

  for (i = 0; i < bs; i++){
    iN = i*N;
    for (j = 0; j < bs; j++){
	  jN = j*N;	
	  iNj = iN + j;
      for  (k = 0; k < bs; k++){  
        cblk[iNj] += ablk[iN + k] * bblk[jN + k];
      }
    }
  }
}


int validar(int n, double *c, char* fileR){
 int validacion = 0;
 double* r = (double *) malloc(n*n*sizeof(double));

	leerMatriz(r,n,fileR);

    if (memcmp(r, c, n*n*sizeof(double)) != 0) {      		
    	validacion = -1;
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



