#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sched.h>

#define PIPE_NAME "/tmp/temp_pipe"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
float valores[3] = {0.0, 0.0, 0.0};
int ti = 0;

// Función del thread de alta prioridad
void *Funcion_Alta_Prioridad(void *arg) {
    int pipe_fd = open(PIPE_NAME, O_RDONLY);
    if (pipe_fd == -1) {
        perror("Error al abrir el pipe");
        return 0;
    }

    float temperature;
    while (read(pipe_fd, &temperature, sizeof(float)) > 0) {
        if (temperature > 90.0) {
            printf("ALERTA: Temperatura excede 90°C: %.2f°C\n", temperature);
        } else {
            // Pasar la temperatura al thread de menor prioridad
            pthread_mutex_lock(&mutex);
            valores[ti] = temperature;
            ti = (ti + 1) % 3;
            pthread_mutex_unlock(&mutex);
        }
    }

    close(pipe_fd);
    return 0;
}

// Función del thread de baja prioridad
void *Funcion_Baja_Prioridad(void *arg) {
    while (1) {
        sleep(1);  // Esperar un segundo antes de calcular el promedio
        pthread_mutex_lock(&mutex);
        float promedio = (valores[0] + valores[1] + valores[2]) / 3;
        pthread_mutex_unlock(&mutex);
        printf("Promedio de las últimas 3 temperaturas: %.2f°C\n", promedio);
    }
}

int main() {
    pthread_t thread_principal, thread_secundario;
    struct sched_param parametros_thread_principal, parametros_thread_secundario;

    // Crear el thread de alta prioridad
    pthread_create(&thread_principal, NULL, Funcion_Alta_Prioridad, NULL);

    // Establecer la prioridad del thread de alta prioridad
    parametros_thread_principal.sched_priority = sched_get_priority_max(SCHED_FIFO);
    pthread_setschedparam(thread_principal, SCHED_FIFO, &parametros_thread_principal);

    // Crear el thread de baja prioridad
    pthread_create(&thread_secundario, NULL, Funcion_Baja_Prioridad, NULL);

    // Establecer la prioridad del thread de baja prioridad
    parametros_thread_secundario.sched_priority = sched_get_priority_min(SCHED_FIFO);
    pthread_setschedparam(thread_secundario, SCHED_FIFO, &parametros_thread_secundario);

    // Esperar a que los threads terminen
    pthread_join(thread_principal, NULL);
    pthread_join(thread_secundario, NULL);

    return 0;
}

