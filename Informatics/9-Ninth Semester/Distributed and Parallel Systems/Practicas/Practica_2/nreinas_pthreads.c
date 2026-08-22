#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int SIZE;
int T;
long global_total = 0;
pthread_mutex_t count_mutex;

double dwalltime() {
    double sec;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}

void solve_recursive(int left, int down, int right, int mask, long *count) {
    if (down == mask) {
        (*count)++;
        return;
    }
    int bitmap = mask & ~(left | down | right);
    while (bitmap) {
        int bit = -bitmap & bitmap;
        bitmap ^= bit;
        solve_recursive((left | bit) << 1, down | bit, (right | bit) >> 1, mask, count);
    }
}

void* worker_nreinas(void* arg) {
    int tid = *(int*)arg;
    int mask = (1 << SIZE) - 1;
    long local_count = 0;

    for (int i = tid; i < SIZE; i += T) {
        int bit = 1 << i;
        solve_recursive(bit << 1, bit, bit >> 1, mask, &local_count);
    }

    pthread_mutex_lock(&count_mutex);
    global_total += local_count;
    pthread_mutex_unlock(&count_mutex);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s N T\n", argv[0]);
        exit(1);
    }
    SIZE = atoi(argv[1]);
    T = atoi(argv[2]);

    pthread_mutex_init(&count_mutex, NULL);
    pthread_t threads[T];
    int tids[T];

    double timetick = dwalltime();

    for (int i = 0; i < T; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, worker_nreinas, &tids[i]);
    }

    for (int i = 0; i < T; i++) {
        pthread_join(threads[i], NULL);
    }

    double total_time = dwalltime() - timetick;
    printf("Pthreads N-Queens N=%d T=%d Tiempo=%f Resultados=%ld\n", SIZE, T, total_time, global_total);

    pthread_mutex_destroy(&count_mutex);
    return 0;
}
