#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>

//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc, char*argv[]){
 double timetick;
 
 	// Chequeo de parámetros. Se recibe N como longitud del arreglo y el numero de repeticiones en que se realiza el calculo
    if (argc != 3) {
        printf("Uso: %s N Repeticiones\n", argv[0]);
        return 1;
    }
	
	unsigned long N = atol(argv[1]);
	unsigned long R = atol(argv[2]);
	unsigned long r;
	unsigned long i;
	unsigned long *a;

	// Aloca memoria para el arreglo
	a = (unsigned long*)malloc(sizeof(unsigned long)*N);

	// Inicializa el arreglo con direccionamiento tradicional a[i]
	timetick = dwalltime();
	for(r=0;r<R;r++){
		for(i=0;i<N;i++){
			a[i] = 1;
		}
	}
	printf("Tiempo de direccionamiento a[i]: %f \n", dwalltime() - timetick);

	// Inicializa el arreglo con direccionamiento a partir de un puntero p
	timetick = dwalltime();
	register unsigned long *p;
	for(r=0;r<R;r++){
		for(p=a ; p < a+N ; p++){
			*p = 1;
		}
	}
	printf("Tiempo de direccionamiento *p: %f \n", dwalltime() - timetick);

	//Libera memoria
	free(a);
 
	return 0;
}

//----------------------------

double dwalltime(){
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}