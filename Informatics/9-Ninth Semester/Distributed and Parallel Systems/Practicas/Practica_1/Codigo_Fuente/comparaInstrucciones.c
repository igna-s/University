#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <sys/time.h>

// Retorna un numero aleatorio de tipo double entre un valor minimo (min) y un valor maximo(max)
double randfrom(double min, double max); 
//Funcion para calcular el tiempo de ejecucion
double dwalltime(void);

int main(int argc, char *argv[]){
 double* x;
 double* y;
 double* resultado;
 double timetick, timeend;
 unsigned long i;
 unsigned long r;
 
	// Chequeo de parámetros. Se recibe N como longitud de los arreglos y el numero de repeticiones en que se realiza el calculo
    if (argc != 3) {
        printf("Uso: %s N Repeticiones\n", argv[0]);
        return 1;
    }

	unsigned long N = atol(argv[1]);
	unsigned long R = atol(argv[2]);
 
	// Aloca memoria
	x=(double*)malloc(sizeof(double)*N);
	y=(double*)malloc(sizeof(double)*N);
	resultado=(double*)malloc(sizeof(double)*N);

	srand (time (NULL));
	//Inicializa los arreglos
	for(i=0;i<N;i++){
		x[i] = 2*(1 + randfrom(0,39916801));
		y[i] = randfrom(1,719);
	}

	//Este for es para eliminar el cool state y limpiar cache
	for(i=0;i<N;i++){
		resultado[i] = x[i]+y[i];
	}

	//Comenzar calculos 
	printf("Ejecutando operaciones\n");
 
	//Suma
	printf("Suma...\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){
			for(i=0;i<N;i++){
				resultado[i] = x[i]+y[i];
			}
		}		
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N*R);
  
	//Resta
	printf("Resta...\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){
			for(i=0;i<N;i++){
				resultado[i] = x[i]-y[i];
			}
		} 	
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N*R);
  
	//Producto
	printf("Producto...\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){ 
			for(i=0;i<N;i++){
				resultado[i] = x[i]*y[i];
			}
		}	
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N*R);
  
	//Division
	printf("Division...\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){
			for(i=0;i<N;i++){
				resultado[i] = x[i]/y[i];
			}
		}	
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N*R);

	// Libera memoria
	free(x);
	free(y);
	free(resultado);

	return(0);
}

//-----------------------------------

double randfrom(double min, double max) {
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double dwalltime(){
        double sec;
        struct timeval tv;

        gettimeofday(&tv,NULL);
        sec = tv.tv_sec + tv.tv_usec/1000000.0;
        return sec;
}