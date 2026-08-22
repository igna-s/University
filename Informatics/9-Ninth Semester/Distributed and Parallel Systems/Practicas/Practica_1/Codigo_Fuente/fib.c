#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#define repeticiones 10

//Calcula Fibonacci recursivo
unsigned long long fibRecursivo(unsigned long long  n);
//Calcula Fibonacci iterativo
unsigned long long fibIterativo(unsigned long long n);
//Para calcular tiempo
double dwalltime();


int main(int argc, char *argv[]){
double timetick, timeend;
unsigned long long N;
unsigned long long resultado;

	// Chequeo de parametros
	if ( (argc < 2) || ((N = atoi(argv[1])) <= 0)){
		printf("\nError en los parametros. Usar: %s N \n", argv[0]);
		exit(1);
	}


  //Fibonacci iterativo
  printf("\n Calculando Fibonacci iterativo para N = %llu...\n",N);
  timetick = dwalltime();
	for(int r=0;r<repeticiones;r++){
		resultado = fibIterativo(N);
	}
  timeend = dwalltime();
  printf(" Resultado = %llu\n",resultado); 
  printf(" Tiempo en segundos: %.10lf \n", (timeend - timetick)/repeticiones);
  
  //Fibonacci recursivo
  printf("\n Calculando Fibonacci recursivo para N = %llu...\n",N);
  timetick = dwalltime();
	for(int r=0;r<repeticiones;r++){
		resultado = fibRecursivo(N); 
	}
  timeend = dwalltime();
  printf(" Resultado = %llu\n",resultado); 
  printf(" Tiempo en segundos: %.10lf \n", (timeend - timetick)/repeticiones);

	
  return(0);

}

//--------------------------------------

unsigned long long fibRecursivo(unsigned long long  n){
  if (n <= 2){
   return 1;
  }else{
   return fibRecursivo(n-1) + fibRecursivo(n - 2);
  }
}

unsigned long long fibIterativo(unsigned long long n){
unsigned long long j = 0;
unsigned long long i = 1;
unsigned long long k;
unsigned long long t;

	for(k=1;k<=n;k++){
		t = i + j;
		i = j;
		j = t;
	}
 	return j;
}

double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}