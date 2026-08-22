/*
 * p3Ej4.c — N-Reinas paralelo  (MPI, patrón Master-Worker / Bag of Tasks)
 *
 * ── Diseño Foster ──────────────────────────────────────────────────────────
 * Descomposición : EXPLORATORIA. El espacio de búsqueda es un árbol de
 *                  backtracking. Se cortan subtárboles en el nivel 1-2 del árbol
 *                  para definir tareas independientes:
 *                  - Tipo 1: (BOARD[0]=esquina, BOARD[1]=posición BOUND1)
 *                    → (SIZEE-2) tareas de Backtrack1.
 *                  - Tipo 2: (BOARD[0]=posición BOUND1 interior)
 *                    → (SIZE/2-1) tareas de Backtrack2.
 *
 * Comunicación   : Dinámica. Master envía una tarea por vez a cada worker
 *                  (MPI_Send/Recv), worker devuelve COUNT8/COUNT4/COUNT2.
 *                  Al terminar todas las tareas, master envía señal de fin.
 *
 * Aglomeración   : Un subtárbol completo por tarea → granularidad media-alta.
 *                  Evita overhead excesivo de comunicación por tarea muy fina.
 *
 * Mapeo          : DINÁMICO centralizado (Bag of Tasks). Las tareas son
 *                  NO UNIFORMES: algunas ramas se podan agresivamente, otras
 *                  generan miles de soluciones. El mapeo estático causaría
 *                  desbalance severo de carga. El mapeo dinámico asegura que
 *                  ningún proceso quede ocioso mientras haya tareas pendientes.
 *
 * Respuestas al práctico:
 *   a) Descomposición exploratoria: árboles de búsqueda con poda.
 *   b) Tarea = subtárbol con BOARD[0] y BOARD[1] fijos (o solo BOARD[0] para Tipo 2).
 *      Las tareas NO son uniformes (poda variable). Mapeo estático → desbalance
 *      de carga: un proceso puede quedar con múltiples tareas "pesadas" y otro
 *      con solo tareas "livianas" que se podan rápido.
 *   c) Implementación con Master-Worker a continuación.
 * ──────────────────────────────────────────────────────────────────────────
 * Compilar: mpicc -O2 -o p3Ej4 p3Ej4.c
 * Ejecutar: mpirun -np <P> ./p3Ej4 <N>    (ej: N=13, N=14)
 * Nota: necesita al menos 2 procesos (1 master + 1+ workers).
 *       Con P=1 ejecuta secuencialmente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAXSIZE 24
#define TAG_TASK   1
#define TAG_RESULT 2
#define TAG_DONE   3

/* ── Variables globales del backtracking (cada proceso tiene su copia) ──── */
int  SIZE, SIZEE;
int  BOARD[MAXSIZE], *BOARDE, *BOARD1, *BOARD2;
int  MASK, TOPBIT, SIDEMASK, LASTMASK, ENDBIT;
int  BOUND1, BOUND2;
long int COUNT8, COUNT4, COUNT2;

/* ── Funciones del algoritmo secuencial (sin modificar) ─────────────────── */
void Check(void)
{
    int *own, *you, bit, ptn;
    if (*BOARD2 == 1) {
        for (ptn=2, own=BOARD+1; own<=BOARDE; own++, ptn<<=1) {
            bit = 1;
            for (you=BOARDE; *you!=ptn && *own>=bit; you--) bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
        if (own > BOARDE) { COUNT2++; return; }
    }
    if (*BOARDE == ENDBIT) {
        for (you=BOARDE-1, own=BOARD+1; own<=BOARDE; own++, you--) {
            bit = 1;
            for (ptn=TOPBIT; ptn!=*you && *own>=bit; ptn>>=1) bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
        if (own > BOARDE) { COUNT4++; return; }
    }
    if (*BOARD1 == TOPBIT) {
        for (ptn=TOPBIT>>1, own=BOARD+1; own<=BOARDE; own++, ptn>>=1) {
            bit = 1;
            for (you=BOARD; *you!=ptn && *own>=bit; you++) bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
    }
    COUNT8++;
}

void Backtrack2(int y, int left, int down, int right)
{
    int bitmap, bit;
    bitmap = MASK & ~(left | down | right);
    if (y == SIZEE) {
        if (bitmap && !(bitmap & LASTMASK)) { BOARD[y] = bitmap; Check(); }
    } else {
        if (y < BOUND1) { bitmap |= SIDEMASK; bitmap ^= SIDEMASK; }
        else if (y == BOUND2) {
            if (!(down & SIDEMASK)) return;
            if ((down & SIDEMASK) != SIDEMASK) bitmap &= SIDEMASK;
        }
        while (bitmap) {
            bitmap ^= BOARD[y] = bit = -bitmap & bitmap;
            Backtrack2(y+1, (left|bit)<<1, down|bit, (right|bit)>>1);
        }
    }
}

void Backtrack1(int y, int left, int down, int right)
{
    int bitmap, bit;
    bitmap = MASK & ~(left | down | right);
    if (y == SIZEE) {
        if (bitmap) { BOARD[y] = bitmap; COUNT8++; }
    } else {
        if (y < BOUND1) { bitmap |= 2; bitmap ^= 2; }
        while (bitmap) {
            bitmap ^= BOARD[y] = bit = -bitmap & bitmap;
            Backtrack1(y+1, (left|bit)<<1, down|bit, (right|bit)>>1);
        }
    }
}

/* ── Ejecuta una tarea y deja resultados en COUNT8/4/2 ─────────────────── */
void run_task(int type, int b1, int b2)
{
    COUNT8 = COUNT4 = COUNT2 = 0;
    BOARDE = &BOARD[SIZEE];

    if (type == 1) {
        /* Backtrack1: primera reina en esquina, segunda en columna b1 */
        BOUND1 = b1;
        BOARD[0] = 1;
        int bit = 1 << b1;
        BOARD[1] = bit;
        Backtrack1(2, (2|bit)<<1, 1|bit, bit>>1);
    } else {
        /* Backtrack2: primera reina en posición interior b1 */
        /* Reconstruir LASTMASK y ENDBIT para esta iteración */
        SIDEMASK = TOPBIT | 1;
        int lm = TOPBIT | 1;
        int eb = TOPBIT >> 1;
        for (int i = 1; i < b1; i++) {  /* aplicar (b1-1) actualizaciones */
            lm |= lm >> 1 | lm << 1;
            eb >>= 1;
        }
        LASTMASK = lm;
        ENDBIT   = eb;
        BOUND1   = b1;
        BOUND2   = b2;
        BOARD1   = &BOARD[b1];
        BOARD2   = &BOARD[b2];
        BOARD[0] = 1 << b1;
        int bit  = BOARD[0];
        Backtrack2(1, bit<<1, bit, bit>>1);
    }
}

/* ── NQueens secuencial (para P=1 o validación) ─────────────────────────── */
void NQueens_seq(long int *total, long int *unique)
{
    COUNT8 = COUNT4 = COUNT2 = 0;
    BOARDE = &BOARD[SIZEE];
    TOPBIT = 1 << SIZEE;
    MASK   = (1 << SIZE) - 1;

    BOARD[0] = 1;
    for (BOUND1=2; BOUND1<SIZEE; BOUND1++) {
        int bit = 1 << BOUND1;
        BOARD[1] = bit;
        Backtrack1(2, (2|bit)<<1, 1|bit, bit>>1);
    }
    long int bt1_c8 = COUNT8, bt1_c4 = COUNT4, bt1_c2 = COUNT2;

    COUNT8 = COUNT4 = COUNT2 = 0;
    SIDEMASK = LASTMASK = TOPBIT | 1;
    ENDBIT = TOPBIT >> 1;
    for (BOUND1=1,BOUND2=SIZE-2; BOUND1<BOUND2; BOUND1++,BOUND2--) {
        BOARD1 = &BOARD[BOUND1];
        BOARD2 = &BOARD[BOUND2];
        BOARD[0] = 1 << BOUND1;
        int bit = BOARD[0];
        Backtrack2(1, bit<<1, bit, bit>>1);
        LASTMASK |= LASTMASK>>1 | LASTMASK<<1;
        ENDBIT >>= 1;
    }
    long int uc = bt1_c8 + COUNT8 + bt1_c4 + COUNT4 + bt1_c2 + COUNT2;
    long int tc = (bt1_c8+COUNT8)*8 + (bt1_c4+COUNT4)*4 + (bt1_c2+COUNT2)*2;
    *unique = uc;
    *total  = tc;
}

int main(int argc, char *argv[])
{
    int rank, nprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    if (argc < 2) {
        if (!rank) fprintf(stderr, "Uso: mpirun -np P ./p3Ej4 N\n");
        MPI_Finalize(); return 1;
    }
    SIZE  = atoi(argv[1]);
    SIZEE = SIZE - 1;
    TOPBIT = 1 << SIZEE;
    MASK   = (1 << SIZE) - 1;

    /* ── Caso P=1: ejecución secuencial ─────────────────────────────────── */
    if (nprocs == 1) {
        double t0 = MPI_Wtime();
        long int total, unique;
        NQueens_seq(&total, &unique);
        double t1 = MPI_Wtime();
        printf("N=%d  P=1 (sec)  UNIQUE=%ld  TOTAL=%ld  Tiempo=%.6f s\n",
               SIZE, unique, total, t1-t0);
        MPI_Finalize(); return 0;
    }

    /* ── Construir lista de tareas ───────────────────────────────────────── */
    /* task_list[i] = {type, b1, b2} */
    int task_list[200][3];
    int ntasks = 0;

    /* Tipo 1: Backtrack1, BOUND1 en [2..SIZEE-1] */
    for (int b = 2; b < SIZEE; b++) {
        task_list[ntasks][0] = 1;
        task_list[ntasks][1] = b;
        task_list[ntasks][2] = 0;
        ntasks++;
    }
    /* Tipo 2: Backtrack2, pares (b1, b2) simétricamente */
    for (int b1=1, b2=SIZE-2; b1<b2; b1++, b2--) {
        task_list[ntasks][0] = 2;
        task_list[ntasks][1] = b1;
        task_list[ntasks][2] = b2;
        ntasks++;
    }

    double t0 = MPI_Wtime();

    if (rank == 0) {
        /* ════════════════════════════════════════════════════════
         * MASTER: distribuye tareas dinámicamente a los workers
         * ════════════════════════════════════════════════════════ */
        long int total_C8 = 0, total_C4 = 0, total_C2 = 0;
        int task[3];           /* {type, b1, b2} */
        long int result[3];    /* {COUNT8, COUNT4, COUNT2} */
        MPI_Status status;
        int cur_task = 0, workers_busy = 0;

        /* Sembrar todos los workers con su primera tarea */
        for (int w = 1; w < nprocs && cur_task < ntasks; w++) {
            task[0] = task_list[cur_task][0];
            task[1] = task_list[cur_task][1];
            task[2] = task_list[cur_task][2];
            MPI_Send(task, 3, MPI_INT, w, TAG_TASK, MPI_COMM_WORLD);
            cur_task++;
            workers_busy++;
        }

        /* Bucle principal: recibir resultado → enviar nueva tarea si hay */
        while (workers_busy > 0) {
            MPI_Recv(result, 3, MPI_LONG, MPI_ANY_SOURCE, TAG_RESULT,
                     MPI_COMM_WORLD, &status);
            int worker = status.MPI_SOURCE;
            total_C8 += result[0];
            total_C4 += result[1];
            total_C2 += result[2];
            workers_busy--;

            if (cur_task < ntasks) {
                task[0] = task_list[cur_task][0];
                task[1] = task_list[cur_task][1];
                task[2] = task_list[cur_task][2];
                MPI_Send(task, 3, MPI_INT, worker, TAG_TASK, MPI_COMM_WORLD);
                cur_task++;
                workers_busy++;
            }
        }

        /* Señal de finalización a todos los workers */
        task[0] = -1;
        for (int w = 1; w < nprocs; w++)
            MPI_Send(task, 3, MPI_INT, w, TAG_DONE, MPI_COMM_WORLD);

        double t1 = MPI_Wtime();
        long int UNIQUE = total_C8 + total_C4 + total_C2;
        long int TOTAL  = total_C8*8 + total_C4*4 + total_C2*2;
        printf("N=%d  P=%d  UNIQUE=%ld  TOTAL=%ld  Tiempo=%.6f s\n",
               SIZE, nprocs, UNIQUE, TOTAL, t1-t0);

    } else {
        /* ════════════════════════════════════════════════════════
         * WORKER: recibir tareas, ejecutar, enviar resultados
         * ════════════════════════════════════════════════════════ */
        int task[3];
        long int result[3];
        MPI_Status status;

        while (1) {
            MPI_Recv(task, 3, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            if (status.MPI_TAG == TAG_DONE) break;

            run_task(task[0], task[1], task[2]);

            result[0] = COUNT8;
            result[1] = COUNT4;
            result[2] = COUNT2;
            MPI_Send(result, 3, MPI_LONG, 0, TAG_RESULT, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
