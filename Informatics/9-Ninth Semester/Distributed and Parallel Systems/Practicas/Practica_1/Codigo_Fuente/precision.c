#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<sys/time.h>
#include<time.h>
#include <math.h>

#ifdef DOUBLE
 typedef double datatype;
#else
 typedef float datatype;	
#endif	

//Calcula el numero de fibonacci, utilizando el numero aureo, para tipos de datos de coma flotante 
datatype fib_aureo(datatype x);
//Calcula el numero de fibonacci de forma iterativa para tipo de dato entero 
int fib_int(int n);
//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc,char*argv[]){	
double timetick;
double endtime;

	// Chequeo de parámetros. Se recibe N como longitud del arreglo.
    if (argc != 2) {
        printf("Uso: %s N\n", argv[0]);
        return 1;
    }

	time_t t;
	srand((unsigned) time(&t)); 

	#ifdef DOUBLE
		printf("Tipo de datos DOUBLE\n");
	#else
		printf("Tipo de datos FLOAT\n");	
	#endif	

	unsigned long N = atol(argv[1]); 
	
	datatype *v;
	datatype *resultado_aureo;
	int *resultado_int;

	// Aloca memoria para el arreglo
	v=(datatype*)malloc(sizeof(datatype)*N);
	// Aloca memoria para el arreglo de resultados calculado con el numero aureo
	resultado_aureo=(datatype*)malloc(sizeof(datatype)*N);
	// Aloca memoria para el arreglo de resultados calculado de forma iterativa
	resultado_int=(int*)malloc(sizeof(int)*N);
	
	unsigned long r;

	//Inicializa el arreglo con valores enteros entre 0 y 44.
	for(r=0;r<N;r++){
		v[r]=rand()%45;	
	}
 
	
	timetick = dwalltime();
		//Calcula fibonacci con el numero aureo para cada elemento del arreglo
		for(r=0;r<N;r++){
			resultado_aureo[r] = fib_aureo(v[r]);	
	}
	endtime = dwalltime() - timetick;

	#ifdef DOUBLE
		printf("Tiempo cálculo aureo (DOUBLE): %.2f segundos\n",endtime);
	#else
		printf("Tiempo cálculo aureo (FLOAT): %.2f segundos\n",endtime);
	#endif


	timetick = dwalltime();
		//Calcula fibonacci iterativo para datos enteros
		for(r=0;r<N;r++){
			resultado_int[r] = fib_int(v[r]);	
		}
	endtime = dwalltime() - timetick;
	printf("Tiempo cálculo iterativo (INT): %.2f segundos\n",endtime); 

	//Calcula el error de precision por tipo de dato
	double error = 0;
	for(r=0;r<N;r++){
		error += abs(resultado_aureo[r] - resultado_int[r]);	
	} 
	printf("Precision (Error Medio):%lf\n",error/N);  

	// Libera memoria
	free(v);
	free(resultado_aureo);
	free(resultado_int);

	return(0);
}

//-----------------------------------

datatype fib_aureo(datatype x){
	#ifdef DOUBLE
		double sqrt5 = sqrt(5);
	#else
		float sqrt5 = sqrtf(5);
	#endif	

	datatype aureo = ((1 + sqrt5)/2);

	#ifdef DOUBLE
		return ( (pow(aureo,x) - pow(1-aureo,x)) / sqrt5 );
	#else
		return ( (powf(aureo,x) - powf(1-aureo,x)) / sqrt5 );
	#endif	
}

int fib_int(int n){
int j = 0;
int i = 1;
int k;
int t;

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