#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s N T\n", argv[0]);
        exit(1);
    }
    int SIZE = atoi(argv[1]);
    int T = atoi(argv[2]);
    int mask = (1 << SIZE) - 1;
    long global_total = 0;

    omp_set_num_threads(T);
    double timetick = dwalltime();

    #pragma omp parallel for schedule(dynamic) reduction(+:global_total)
    for (int i = 0; i < SIZE; i++) {
        long local_count = 0;
        int bit = 1 << i;
        solve_recursive(bit << 1, bit, bit >> 1, mask, &local_count);
        global_total += local_count;
    }

    double total_time = dwalltime() - timetick;
    printf("OpenMP N-Queens N=%d T=%d Tiempo=%f Resultados=%ld\n", SIZE, T, total_time, global_total);

    return 0;
}
