#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <sys/time.h>
#include <sys/resource.h>

// Inicializa un arreglo de enteros de dimension N
int* inicializarArreglo(int* a,unsigned long N);
//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc, char *argv[]){
double timetick;
time_t t;
srand((unsigned) time(&t));
int* a;

	// Chequeo de parámetros. Se recibe N como longitud del arreglo. P es la posicion seleccionada
    if (argc != 3) {
        printf("Uso: %s N P\n", argv[0]);
        return 1;
    }

	unsigned long N = atol(argv[1]);
	unsigned long posicionSeleccionada = atol(argv[2]);
	
	if (posicionSeleccionada >= N) {
		printf("Posicion a buscar fuera de rango\n");
		return 1;
	}
	
	unsigned long numBytes = sizeof(int)*N;
	unsigned long i;
	unsigned long menores1=0;
	unsigned long menores2=0;
	unsigned long menores3=0;

	// Aloca memoria
	a=(int*)malloc(numBytes);
	
	// Inicializa el arreglo
	a=inicializarArreglo(a,N);	

	//Solucion 1
	timetick = dwalltime();
	// Recorre el arreglo y pregunta por la posicion seleccionada en cada iteracion
	for(i=0;i<N;i++){
		if(i!=posicionSeleccionada){
			if(a[i]<a[posicionSeleccionada])
				menores1++;	
		}
	}
	printf("-> Tiempo Solucion 1 (Pregunta por la posicion seleccionada en cada iteracion): %f\n", dwalltime() - timetick);
	
	// Solucion 2
	timetick = dwalltime();
	// Recorre la primera parte del arreglo hasta la posicion anterior a la seleccionada
	for(i=0;i<posicionSeleccionada;i++){
		if(a[i]<a[posicionSeleccionada])
			menores2++;	
	}
	// Recorre la segunda parte del arreglo desde la posicion siguiente a la seleccionada
	for(i=posicionSeleccionada+1;i<N;i++){
		if(a[i]<a[posicionSeleccionada])
			menores2++;	
	}	
	printf("-> Tiempo Solucion 2 (Saltea la posicion seleccionada): %f\n", dwalltime() - timetick);

	//Solucion 3
	timetick = dwalltime();
	// Recorre el arreglo pero nunca pregunta por la posicion seleccionada. Procesa la posicion seleccionada innecesariamente
	for(i=0;i<N;i++){
		if(a[i]<a[posicionSeleccionada])
			menores3++;	
	}
	printf("-> Tiempo Solucion 3 (Procesa la posicion seleccionada innecesariamente): %f\n", dwalltime() - timetick);

	if ((menores1==menores2) && (menores2==menores3)){
		printf("RESULTADO CORRECTO: los tres cálculos son iguales\n");
	}else{
		printf("ERROR\n");
	}
	
	// Libera memoria
	free(a);
	return 0;
}

//-------------------------------

int* inicializarArreglo(int* a,unsigned long N){
unsigned long i;
	for(i=0;i<N;i++){
		a[i]=rand()%1000;
	}
	
	return a;
}

double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}