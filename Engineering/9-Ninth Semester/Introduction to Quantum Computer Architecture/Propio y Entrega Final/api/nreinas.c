/**************************************************************************/
/* N-Queens Solutions  ver3.1               takaken July/2003             */
/**************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/* 
 * dwalltime: Devuelve el tiempo en segundos desde un punto en el pasado.
 * Útil para medir la duración de la ejecución del algoritmo. 
 */
double dwalltime();

/* MAXSIZE: Tamaño máximo del tablero (hasta 24x24) */
#define  MAXSIZE  24
#define  MINSIZE   2

/* Variables Globales Compartidas del Algoritmo Takaken */
int  SIZE, SIZEE;                                   /* SIZE = N, SIZEE = N - 1 */
int  BOARD[MAXSIZE], *BOARDE, *BOARD1, *BOARD2;     /* Arreglos que guardan las posiciones parciales (estado) de las reinas */
int  MASK, TOPBIT, SIDEMASK, LASTMASK, ENDBIT;      /* Máscaras de bits utilizadas para filtrar posiciones válidas e inválidas */
int  BOUND1, BOUND2;                                /* Límites de poda para descartar soluciones simétricas de forma temprana */

/* Contadores para las soluciones agrupadas por su grado de simetría */
long int  COUNT8, COUNT4, COUNT2;
long int  TOTAL, UNIQUE; /* TOTAL: Total real de soluciones. UNIQUE: Soluciones base sin contar rotaciones/reflexiones. */

/**********************************************/
/* Display the Board Image                    */
/* Muestra el tablero actual por pantalla.    */
/**********************************************/
void Display(void)
{
    int  y, bit;

    printf("N= %d\n", SIZE);
    for (y=0; y<SIZE; y++) {
        for (bit=TOPBIT; bit; bit>>=1)
            printf("%s ", (BOARD[y] & bit)? "Q": "-"); /* Imprime 'Q' si la reina está en la posición 'bit' o '-' si no */
        printf("\n");
    }
    printf("\n");
}

/**********************************************/
/* Check Unique Solutions                     */
/* Verifica el grado de simetría de una       */
/* solución encontrada. Dependiendo de esto,  */
/* incrementará COUNT2, COUNT4 o COUNT8.      */
/**********************************************/
void Check(void)
{
    int  *own, *you, bit, ptn;

    /* Rotación 90°: Compara si el tablero es idéntico a su versión girada 90 grados */
    if (*BOARD2 == 1) {
        for (ptn=2,own=BOARD+1; own<=BOARDE; own++,ptn<<=1) {
            bit = 1;
            for (you=BOARDE; *you!=ptn && *own>=bit; you--)
                bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
        if (own > BOARDE) {
            COUNT2++; /* Multiplica por 2 en el conteo total final */
            //Display();
            return;
        }
    }

    /* Rotación 180°: Compara el tablero con su versión girada 180 grados */
    if (*BOARDE == ENDBIT) {
        for (you=BOARDE-1,own=BOARD+1; own<=BOARDE; own++,you--) {
            bit = 1;
            for (ptn=TOPBIT; ptn!=*you && *own>=bit; ptn>>=1)
                bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
        if (own > BOARDE) {
            COUNT4++; /* Multiplica por 4 en el conteo total final */
            //Display();
            return;
        }
    }

    /* Rotación 270°: Compara el tablero con su versión girada 270 grados */
    if (*BOARD1 == TOPBIT) {
        for (ptn=TOPBIT>>1,own=BOARD+1; own<=BOARDE; own++,ptn>>=1) {
            bit = 1;
            for (you=BOARD; *you!=ptn && *own>=bit; you++)
                bit <<= 1;
            if (*own > bit) return;
            if (*own < bit) break;
        }
    }
    
    /* Si la solución no coincide con sus rotadas, es asimétrica y cuenta por 8 */
    COUNT8++;
    //Display();
}

/**********************************************/
/* First queen is inside                      */
/* Función recursiva de Backtracking.         */
/* Se usa cuando la reina de la primera fila  */
/* se colocó en una posición interior.        */
/**********************************************/
void Backtrack2(int y, int left, int down, int right)
{
    int  bitmap, bit;

    /* Determinar posiciones libres disponibles en la fila actual */
    bitmap = MASK & ~(left | down | right);
    if (y == SIZEE) {
        /* Caso base: si llegamos a la última fila */
        if (bitmap) {
            /* Filtrar espejismos utilizando LASTMASK */
            if (!(bitmap & LASTMASK)) {
                BOARD[y] = bitmap;
                Check(); /* Llamamos a verificar sus simetrías */
            }
        }
    } else {
        /* Poda para evitar recorrer sub-árboles ya cubiertos por otra simetría */
        if (y < BOUND1) {
            bitmap |= SIDEMASK;
            bitmap ^= SIDEMASK;
        } else if (y == BOUND2) {
            if (!(down & SIDEMASK)) return;
            if ((down & SIDEMASK) != SIDEMASK) bitmap &= SIDEMASK;
        }
        
        /* Mientras queden lugares donde poner una reina en esta fila */
        while (bitmap) {
            bitmap ^= BOARD[y] = bit = -bitmap & bitmap; /* Tomamos la primera posición libre de derecha a izquierda */
            /* Llamada recursiva avanzando fila y propagando restricciones (left, down, right) */
            Backtrack2(y+1, (left | bit)<<1, down | bit, (right | bit)>>1);
        }
    }
}

/**********************************************/
/* First queen is in the corner               */
/* Función recursiva de Backtracking.         */
/* Se usa cuando la primera reina (fila 0)    */
/* arranca en una esquina.                    */
/**********************************************/
void Backtrack1(int y, int left, int down, int right)
{
    int  bitmap, bit;

    /* Calcular espacios libres */
    bitmap = MASK & ~(left | down | right);
    if (y == SIZEE) {
        /* Al llegar a la última fila, si hay posición libre... */
        if (bitmap) {
            BOARD[y] = bitmap;
            COUNT8++; /* Las soluciones que empiezan en esquinas siempre carecen de simetría (cuentan x 8) */
            //Display();
        }
    } else {
        /* Poda para sub-árboles simétricos */
        if (y < BOUND1) {
            bitmap |= 2;
            bitmap ^= 2;
        }
        
        /* Probar colocar la reina en los espacios disponibles de esta fila */
       while (bitmap) {
            bitmap ^= BOARD[y] = bit = -bitmap & bitmap;
            /* Llamada recursiva a la siguiente fila */
            Backtrack1(y+1, (left | bit)<<1, down | bit, (right | bit)>>1);
        }
    }
}

/**********************************************/
/* Search of N-Queens                         */
/* Inicia la exploración generando las        */
/* primeras ramas del árbol de soluciones.    */
/**********************************************/
void NQueens(void)
{
    int  bit, cant;

    /* Initialize: Inicialización de variables globales, límites y contadores */
    COUNT8 = COUNT4 = COUNT2 = 0;
    SIZEE  = SIZE - 1;               /* Último índice del tablero (filas de 0 a SIZEE) */
    BOARDE = &BOARD[SIZEE];          /* Puntero rápido a la última fila */
    TOPBIT = 1 << SIZEE;             /* Bit que representa la columna de más a la izquierda */
    MASK   = (1 << SIZE) - 1;        /* Máscara donde las N columnas son '1' */

    /* Parte 1: Exploración con la reina de la Fila 0 en la esquina derecha (bit 1).
     * 0:000000001
     * 1:011111100
     */
    BOARD[0] = 1;
    for (BOUND1=2; BOUND1<SIZEE; BOUND1++) {
        BOARD[1] = bit = 1 << BOUND1;
        /* Lanzar Backtrack1 a partir de la fila 2 */
        Backtrack1(2, (2 | bit)<<1, 1 | bit, bit>>1);
    }
    
    /* Parte 2: Exploración con la reina de la Fila 0 en el interior.
     * 0:000001110
     */
    SIDEMASK = LASTMASK = TOPBIT | 1;
    ENDBIT = TOPBIT >> 1;
    for (BOUND1=1,BOUND2=SIZE-2; BOUND1<BOUND2; BOUND1++,BOUND2--) {
        BOARD1 = &BOARD[BOUND1];
        BOARD2 = &BOARD[BOUND2];
        BOARD[0] = bit = 1 << BOUND1;
        /* Lanzar Backtrack2 a partir de la fila 1 */
        Backtrack2(1, bit<<1, bit, bit>>1);
        LASTMASK |= LASTMASK>>1 | LASTMASK<<1;
        ENDBIT >>= 1;
    }

    /* Unique and Total Solutions */
    /* UNIQUE: Cantidad de tableros resueltos sin contar si son rotaciones el uno del otro */
    UNIQUE = COUNT8     + COUNT4     + COUNT2;
    /* TOTAL: Multiplicamos cada categoría de solución por su grado de simetría respectivo (8, 4 o 2) */
    TOTAL  = COUNT8 * 8 + COUNT4 * 4 + COUNT2 * 2;
    
}

/**********************************************/
/* N-Queens Solutions MAIN                    */
/**********************************************/
int main(int argC, char *argV[])
{  double tIni, tFin;

    SIZE=atoi(argV[1]); 
    tIni= dwalltime();
    NQueens();
    tFin= dwalltime();

    printf("Número de resultados: %lu -  Tiempo Total: %f segundos \n", TOTAL, tFin-tIni);
    return 0;
}

#include <sys/time.h>

/* Función auxiliar implementada al final para medir tiempo. */
double dwalltime()
{
	double sec;
	struct timeval tv;

	gettimeofday(&tv,NULL);
	sec = tv.tv_sec + tv.tv_usec/1000000.0;
	return sec;
}
