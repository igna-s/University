#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>

//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc, char* argv[]){
	
  	// Chequeo de parámetros. Se recibe N como longitud de los arreglos y m que es un divisor potencia de 2
    if (argc != 3) {
        printf("Uso: %s N m\n", argv[0]);
        return 1;
    }
	
	unsigned long N = atol(argv[1]);
	unsigned long m = atol(argv[2]);
	
	// Chequea si m es potencia de 2
	if (m <= 0 || (m & (m - 1)) != 0) {
		printf("m no es potencia de 2.\n");
		return 1;
	}
	
	unsigned long* a;
	unsigned long* resultModulo;
	unsigned long* resultOpt;
	
	// Aloca memoria
	a = (unsigned long*)malloc(sizeof(unsigned long)*N);
	resultModulo = (unsigned long*)malloc(sizeof(unsigned long)*N);
	resultOpt = (unsigned long*)malloc(sizeof(unsigned long)*N);
	unsigned long i;
		
	//Inicializa el arreglo a	
	for(i=0;i<N;i++){
		a[i]=i;
	}

	//Calculo usando %
	double timetick = dwalltime();
	for(i=0;i<N;i++){
		resultModulo[i] = i%m;
	}
	printf("Tiempo usando %%: %f \n", dwalltime() - timetick);
	 
	//Calculo usando la equivalencia
	timetick = dwalltime();
	for(i=0;i<N;i++){
		resultOpt[i] = i&(m-1);
	}
	printf("Tiempo usando equivalencia: %f \n", dwalltime() - timetick);
	
	//Validando resultados
	for(i=0;i<N;i++){
		if(resultModulo[i]!=resultOpt[i]) printf("Error\n");
	}
	
	// Libera memoria
	free(a);
	free(resultModulo);
	free(resultOpt);
	
	return 0;
}

//---------------------------------------------

double dwalltime(){
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}