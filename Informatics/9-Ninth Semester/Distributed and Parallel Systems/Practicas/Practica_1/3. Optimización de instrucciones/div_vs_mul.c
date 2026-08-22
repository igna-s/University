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
 double *resultado1;
 double *resultado2;
 double y1=5;
 double y2=0.2;
 
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
	resultado1=(double*)malloc(sizeof(double)*N);
	resultado2=(double*)malloc(sizeof(double)*N);

	srand (time (NULL));
	//Inicializa el arreglo
	for(i=0;i<N;i++){
		x[i] = 2*(1 + randfrom(0,39916801));
	}

	//Este for es para eliminar el cool state y limpiar cache
	for(i=0;i<N;i++){
		resultado1[i] = x[i]*y1;
		resultado2[i] = x[i]*y2;
	}
	

	//Comenzar calculos 

	//Division
	printf("Dividir por 5\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){
			for(i=0;i<N;i++){
				resultado1[i] = x[i]/y1;
			}
		}	
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N);
  
	//Producto
	printf("Multiplicar por 0.2\n");
	timetick = dwalltime();
		for(r=0;r<R;r++){
			for(i=0;i<N;i++){
				resultado2[i] = x[i]*y2;
			}
		}	
	timeend = dwalltime();
	printf(" Tiempo total en segundos: %.10lf \n", (timeend - timetick));
	printf(" Tiempo promedio en segundos: %.10lf \n", (timeend - timetick)/N);

	for(i=0;i<N;i++){
		//Calculo de resultados con analisis de precisión 4 digitos 
		if (abs(resultado1[i] - resultado2[i]) > 0.0001){
			printf("Error en resultado: %f <> %f \n",resultado1[i],resultado2[i]);
		}
	}	

	// Liberar memoria
	free(x);
	free(resultado1);
	free(resultado2);
  
	return(0);
}

//-------------------------------------------

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
