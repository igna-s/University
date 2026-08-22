#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

// Mezcla dos arreglos, arregloA y arregloB, de longitud NA y NB, respectivamente, y lo deja en un arreglo de salida
void mezcla(int* arregloA, int NA, int* arregloB, int NB, int* arregloDeSalida);
// Ordenacion iterativa de un arreglo de longitud N usando un arreglo auxiliar
// El resultado queda en el arreglo de entrada
void ordenacion(int** arreglo,int N, int** arregloAuxiliar);
// Intercambia dos punteros a entero
void intercambio(int** p1,int** p2);
// Inicializa el arreglo
int* inicializarArreglo(int* arreglo, int N);
// Valida si el arreglo está ordenado
int validar(int* arreglo,int N);
//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);


int main(int argc, char* argv[]){
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
	int* arregloDeSalida;
	double timetick;
 
	// Aloca memoria
	arreglo = (int*)malloc(sizeof(int)*N);
	arregloDeSalida = (int*)malloc(sizeof(int)*N);

	//Inicializa el arreglo
	arreglo = inicializarArreglo(arreglo,N);

	timetick = dwalltime();
		//Ordena
		ordenacion(&arreglo,N,&arregloDeSalida);
	printf("Tiempo en segundos %f \n", dwalltime() - timetick);
	
	
	// Valida
    if (validar(arreglo,N))
        printf("--ORDENADO OK--\n");
    else
        printf("--ERROR--\n");
	
	// Libera memoria	
	free(arreglo);
	free(arregloDeSalida);
	return 0;
	
}

//-----------------------------------------

void mezcla(int* arregloA, int NA, int* arregloB, int NB, int* arregloDeSalida){
 int indiceA = 0;
 int indiceB = 0;
 int indiceDeSalida;
 int limiteIndiceDeSalida = NA + NB;
 
	for(indiceDeSalida=0; indiceDeSalida < limiteIndiceDeSalida; indiceDeSalida++){
		if( (indiceB == NB) || ( (indiceA < NA) && (arregloA[indiceA] <= arregloB[indiceB]) ) ){
			arregloDeSalida[indiceDeSalida] = arregloA[indiceA];
			indiceA++;
		}else if( (indiceA == NA) || ( (indiceB < NB) && (arregloA[indiceA] > arregloB[indiceB]) ) ){
			arregloDeSalida[indiceDeSalida] = arregloB[indiceB];
			indiceB++;	
		}		
	}
	
}

void ordenacion(int** arreglo,int N, int** arregloAuxiliar){
int longitudDeLaParte;
int posicionDeLaParte;
int mitad = N/2;
int* arregloA;
int* arregloB;
int* arregloDeSalida;
	
	for(longitudDeLaParte=1;longitudDeLaParte<=mitad;longitudDeLaParte*=2){
		for(posicionDeLaParte=0;posicionDeLaParte<N;posicionDeLaParte+=2*longitudDeLaParte){
			arregloA = *arreglo + posicionDeLaParte;
			arregloB = arregloA + longitudDeLaParte;
			arregloDeSalida = *arregloAuxiliar + posicionDeLaParte;
			mezcla(arregloA,longitudDeLaParte,arregloB,longitudDeLaParte,arregloDeSalida);	
		}				
		//Intercambiar punteros
		intercambio(arreglo,arregloAuxiliar);			
	}	
		
}

void intercambio(int** p1,int** p2){
 int* aux = *p1;	

	*p1 = *p2;
	*p2 = aux;
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
