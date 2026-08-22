#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

// Funcion auxiliar para mezclar dos partes de un arreglo
void merge(int *arr, int *temp, int left, int mid, int right);
// Ordenacion iterativa de un arreglo de longitud N
void ordenacion(int *arr, int n);
// Inicializa el arreglo
int* inicializarArreglo(int* arreglo, int N);
// Valida si el arreglo está ordenado
int validar(int* arreglo,int N);
//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc, char *argv[]) {
int exp;
	
	// Chequeo de parámetros. Se recibe un exponente (exp) para ordenar un arreglo de 2^exp elementos.
    if (argc != 2) {
        printf("Uso: %s exp\n", argv[0]);
        return 1;
    }

	// El exponente no debe superar 30 por el rango de enteros 
    exp = atoi(argv[1]);
    if (exp < 0 || exp > 30) {
        printf("N debe estar entre 0 y 30\n");
        return 1;
    }

 	int N = 1<<exp; // Calcula N=2^exp
	int* arreglo;	
	double timetick;	
	
	// Aloca memoria
    arreglo = (int *)malloc(N * sizeof(int));

	//Inicializa el arreglo
	arreglo = inicializarArreglo(arreglo,N);

	timetick = dwalltime();
		//Ordena
		ordenacion(arreglo,N);
	printf("Tiempo en segundos %f \n", dwalltime() - timetick);

	// Valida
    if (validar(arreglo,N))
        printf("--ORDENADO OK--\n");
    else
        printf("--ERROR--\n");
	
	// Libera memoria
    free(arreglo);
    return 0;
}

//-----------------------------------------

void merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copiar de nuevo al arreglo original
    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void ordenacion(int *arr, int n) {
    int *temp = (int *)malloc(n * sizeof(int));

    for (int sz = 1; sz < n; sz *= 2) {
        for (int left = 0; left < n; left += 2 * sz) {
            int mid = left + sz - 1;
            int right = (left + 2 * sz - 1 < n - 1) ? left + 2 * sz - 1 : n - 1;
            if (mid < right) merge(arr, temp, left, mid, right);
        }
    }

    free(temp);
}

int* inicializarArreglo(int* arreglo, int N){
	srand(time(NULL));
	//Genera un arreglo con valores aleatorios entre 0 y 99
    for (int i = 0; i < N; i++) {
        arreglo[i] = rand() % 100;
	}
	return arreglo;
}

int validar(int* arreglo,int N){
int ordenado = TRUE;
int i = 1;

    while (i < N && ordenado) {
        ordenado = (arreglo[i-1] <= arreglo[i]);
        i++;
    }

	return ordenado;
}

double dwalltime(void){
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}