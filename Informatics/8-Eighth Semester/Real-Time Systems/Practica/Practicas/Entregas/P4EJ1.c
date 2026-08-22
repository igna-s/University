#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define CANT_ITERACIONES 1000
#define PERIODO 10000  // 10 ms (100 Hz)

void *thread_function(void *arg) {
    struct timespec sig, act;
    long suma = 0;
    int numero_thread = *(int *)arg;

    clock_gettime(CLOCK_MONOTONIC, &sig);

    for (int i = 0; i < CANT_ITERACIONES; i++) {
        sig.tv_nsec += PERIODO * 1000;
        while (sig.tv_nsec >= 1000000000) {
            sig.tv_nsec -= 1000000000;
            sig.tv_sec++;
        }

        // 
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &sig, NULL);

        // 
        clock_gettime(CLOCK_MONOTONIC, &act);
        long latencia = (act.tv_sec - sig.tv_sec) * 1000000000L + (act.tv_nsec - sig.tv_nsec);
        if (latencia > 0) {
            suma += latencia;
        }
    }

    double promedio_latencia = (double)suma / CANT_ITERACIONES;
    printf("Thread %d latencia promedio: %.2f us\n", numero_thread, promedio_latencia / 1000.0);

    return 0;
}

int main() {
    pthread_t thread1, thread2;
    int numero_thread1 = 1, numero_thread2 = 2;

    // Crear threads
    pthread_create(&thread1, NULL, thread_function, &numero_thread1);
    pthread_create(&thread2, NULL, thread_function, &numero_thread2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

