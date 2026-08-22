#!/bin/bash
# run_all.sh — Compila y ejecuta todos los ejercicios de Práctica 3 (MPI)
# Usa las matrices provistas por la cátedra (A*.m row-major, B*.m col-major, R*.m validación).
# Resultados guardados en resultados.txt.

set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

OUTFILE="resultados.txt"
> "$OUTFILE"

# ── Parámetros configurables ──────────────────────────────────────────────────
MATDIR="/mnt/d/Concurrencia-UNLP/Practica_1/Matrices"
MAT_SIZES=(512 1024 2048)   # tamaños de matrices (deben existir A/B/R en MATDIR)
PROCS=(1 2 4 8)             # procesos (potencias de 2)
BS=64                       # block size para Ej 1c
QUEENS=(12 13 14)           # tableros N-Reinas
MERGE_EXP=(20 22)           # mergesort: N = 2^exp
MPIRUN="mpirun --oversubscribe --allow-run-as-root"

# ── Helpers ───────────────────────────────────────────────────────────────────
log()  { echo "$@" | tee -a "$OUTFILE"; }
sep()  { log; log "══════════════════════════════════════════════════════"; log "  $*"; log "══════════════════════════════════════════════════════"; }
run() {
    local cmd="$*"
    log "  \$ $cmd"
    local out
    out=$(eval "$cmd" 2>&1) || true
    echo "$out" | tee -a "$OUTFILE"
    echo "$out" | grep -qi "fallo" && log "  [!] FALLO DETECTADO"
    log ""
}

# ── Paso 1: Compilar ──────────────────────────────────────────────────────────
sep "PASO 1: COMPILACIÓN"
make all 2>&1 | tee -a "$OUTFILE" && log "  => OK"

# ── Paso 2: Verificar matrices disponibles ────────────────────────────────────
sep "PASO 2: VERIFICACIÓN DE MATRICES (cátedra)"
for N in "${MAT_SIZES[@]}"; do
    for f in "A${N}.m" "B${N}.m" "R${N}.m"; do
        if [ -f "$MATDIR/$f" ]; then
            log "  [OK] $MATDIR/$f"
        else
            log "  [!!] FALTA: $MATDIR/$f  (se saltarán las corridas con N=$N)"
        fi
    done
done

# ── Ejercicio 1a — mm_naive paralelo ─────────────────────────────────────────
sep "EJERCICIO 1a: mm_naive optimizado (MPI)"
log "  C = A * B  |  B almacenada column-major  |  validación vs R*.m"
log ""
for N in "${MAT_SIZES[@]}"; do
    [ ! -f "$MATDIR/A${N}.m" ] && continue
    log "  ── N=$N ──────────────────────────"
    for P in "${PROCS[@]}"; do
        (( N % P != 0 )) && { log "  N=$N P=$P: saltado (N%P≠0)"; continue; }
        run $MPIRUN -np $P ./p3Ej1a $N "$MATDIR/A${N}.m" "$MATDIR/B${N}.m" "$MATDIR/R${N}.m"
    done
done

# ── Ejercicio 1b — C = A*A paralelo ──────────────────────────────────────────
sep "EJERCICIO 1b: C = A·A autoproducto (MPI)"
log "  Validación: rank 0 computa A×A secuencial e informa  (no requiere archivo R)"
log ""
for N in "${MAT_SIZES[@]}"; do
    [ ! -f "$MATDIR/A${N}.m" ] && continue
    log "  ── N=$N ──────────────────────────"
    for P in "${PROCS[@]}"; do
        (( N % P != 0 )) && { log "  N=$N P=$P: saltado"; continue; }
        run $MPIRUN -np $P ./p3Ej1b $N "$MATDIR/A${N}.m"
    done
done

# ── Ejercicio 1c — mmblk por bloques paralelo ────────────────────────────────
sep "EJERCICIO 1c: mmblk por bloques (MPI)  [BS=$BS y BS=128]"
log "  C = A * B  |  B column-major  |  validación vs R*.m"
log ""
for N in "${MAT_SIZES[@]}"; do
    [ ! -f "$MATDIR/A${N}.m" ] && continue
    for bs in $BS 128; do
        (( N % bs != 0 )) && continue
        log "  ── N=$N  BS=$bs ──────────────────"
        for P in "${PROCS[@]}"; do
            (( N % P != 0 )) && { log "  N=$N P=$P: saltado"; continue; }
            run $MPIRUN -np $P ./p3Ej1c $N $bs "$MATDIR/A${N}.m" "$MATDIR/B${N}.m" "$MATDIR/R${N}.m"
        done
    done
done

# ── Ejercicio 1c BLAS — mmblk_blas (MPI + cblas_dgemm) ───────────────────────
sep "EJERCICIO 1c BLAS: mmblk_blas (MPI + cblas_dgemm)"
log "  C = A * B  |  B column-major  |  validación vs R*.m"
log ""
make blas 2>&1 | tee -a "$OUTFILE" && log "  => BLAS OK" || log "  => BLAS FALLO AL COMPILAR"

for N in "${MAT_SIZES[@]}"; do
    [ ! -f "$MATDIR/A${N}.m" ] && continue
    for bs in $BS 128; do
        (( N % bs != 0 )) && continue
        log "  ── N=$N  BS=$bs ──────────────────"
        for P in "${PROCS[@]}"; do
            (( N % P != 0 )) && { log "  N=$N P=$P: saltado"; continue; }
            run $MPIRUN -np $P ./p3Ej1c_blas $N $bs "$MATDIR/A${N}.m" "$MATDIR/B${N}.m" "$MATDIR/R${N}.m"
        done
    done
done

# ── Ejercicio 2 — estadísticas de matriz ─────────────────────────────────────
sep "EJERCICIO 2: Mínimo, máximo y promedio (MPI)"
log "  Datos generados internamente (srand 42)  |  validación inline"
log ""
for N in "${MAT_SIZES[@]}"; do
    log "  ── N=$N ──────────────────────────"
    for P in "${PROCS[@]}"; do
        total=$(( N * N ))
        (( total % P != 0 )) && { log "  N²=$total P=$P: saltado"; continue; }
        run $MPIRUN -np $P ./p3Ej2 $N
    done
done

# ── Ejercicio 3 — transposición ──────────────────────────────────────────────
sep "EJERCICIO 3: Transposición N×N (MPI_Alltoall)"
log "  Datos generados internamente  |  validación: T[j][i]==A[i][j]"
log ""
for N in "${MAT_SIZES[@]}"; do
    log "  ── N=$N ──────────────────────────"
    for P in "${PROCS[@]}"; do
        (( N % P != 0 )) && { log "  N=$N P=$P: saltado"; continue; }
        run $MPIRUN -np $P ./p3Ej3 $N
    done
done

# ── Ejercicio 4 — N-Reinas ───────────────────────────────────────────────────
sep "EJERCICIO 4: N-Reinas (Master-Worker / Bag of Tasks)"
log "  Mapeo dinámico — tareas NO uniformes — P=1 como referencia secuencial"
log ""
for N in "${QUEENS[@]}"; do
    log "  ── N=$N reinas ───────────────────"
    run $MPIRUN -np 1  ./p3Ej4 $N
    for P in 2 4 8; do
        run $MPIRUN -np $P ./p3Ej4 $N
    done
done

# ── Ejercicio 5 — Merge Sort ─────────────────────────────────────────────────
sep "EJERCICIO 5: Merge Sort paralelo (árbol binario de fusiones)"
log "  Validación: igual a qsort secuencial  |  N potencia de 2"
log ""
for EXP in "${MERGE_EXP[@]}"; do
    N=$(( 1 << EXP ))
    log "  ── N=2^$EXP = $N ─────────────────"
    run $MPIRUN -np 1 ./p3Ej5 $N
    for P in 2 4 8; do
        run $MPIRUN -np $P ./p3Ej5 $N
    done
done

# ── Resumen ───────────────────────────────────────────────────────────────────
sep "RESUMEN"
FALLOS=$(grep -c "\[!\] FALLO" "$OUTFILE" || true)
log "Fallos detectados: $FALLOS"
log "Resultados en:     $SCRIPT_DIR/$OUTFILE"
log "Fecha:             $(date)"
