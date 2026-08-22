#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>    // Para tipos de datos como pid_t
#include <sys/stat.h>     // Para mkfifo
#include <fcntl.h>        // Para constantes como O_WRONLY

#define PIPE_NAME "/tmp/temp_pipe"

int main() {
    FILE *file = fopen("temperaturas.txt", "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }

    int delay_ns;
    float temperature;
    int pipe_fd;

    // Crear un pipe
    mkfifo(PIPE_NAME, 0666);

    // Abrir el pipe para escritura
    pipe_fd = open(PIPE_NAME, O_WRONLY);
    if (pipe_fd == -1) {
        perror("Error al abrir el pipe");
        return 1;
    }

    struct timespec delay;
    while (fscanf(file, "%d\t%f", &delay_ns, &temperature) == 2) {
        delay.tv_sec = delay_ns / 1000000000;
        delay.tv_nsec = delay_ns % 1000000000;

        // Esperar el tiempo especificado
        nanosleep(&delay, NULL);

        // Escribir la temperatura en el pipe
        write(pipe_fd, &temperature, sizeof(float));
    }

    printf("Archivo finalizado");

    close(pipe_fd);
    fclose(file);
    unlink(PIPE_NAME);

    return 0;
}

