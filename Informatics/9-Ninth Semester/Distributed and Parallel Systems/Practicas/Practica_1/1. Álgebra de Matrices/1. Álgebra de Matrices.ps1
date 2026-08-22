# 1. Algebra de Matrices.ps1
# Script de automatización para la Práctica 0

$MATRICES_DIR = "..\..\Matrices\"
$OUTPUT_FILE = "1. Álgebra de Matrices.txt"
$SIZES = @(512, 1024, 2048)
$BLOCK_SIZES = @(16, 32, 64, 128)

# Compilación
Write-Host "Compilando programas C..."
gcc -o mm_naive mm_naive.c
gcc -o mm_naive_direct mm_naive_direct.c
gcc -o mm_aa mm_aa.c
gcc -o mmblk mmblk.c
gcc -o mmblk_blas mmblk_blas.c
gcc -o mm_triangular mm_triangular.c

$report = @()
$report += "================================================================"
$report += "Incisos: 1. Algebra de Matrices"
$report += "================================================================`n"

# --- Inciso a ---
Write-Host "Ejecutando Inciso a..."
$report += "1.a. Analisis de mm_naive, acceso directo y localidad (B Col-Major)"
$report += "N`tOriginal (B Row)`tDirecto (B Row)`tDirecto (B Col)"
$report += ("-" * 70)

foreach ($n in $SIZES) {
    $fA = "$MATRICES_DIR" + "A$n.m"
    $fBf = "$MATRICES_DIR" + "Bf$n.m"
    $fBc = "$MATRICES_DIR" + "B$n.m"
    $fR = "$MATRICES_DIR" + "R$n.m"
    
    # Original
    $out_orig = ./mm_naive $n $fA $fBf $fR | Out-String
    $t_orig = "Err"
    if ($out_orig -match "Tiempo en segundos ([\d\.]+)") { $t_orig = $Matches[1] }
    
    # Direct Row
    $out_dir_row = ./mm_naive_direct $n $fA $fBf $fR 0 | Out-String
    $t_dir_row = "Err"
    if ($out_dir_row -match "Time\(s\):([\d\.]+)") { $t_dir_row = $Matches[1] }
    
    # Direct Col
    $out_dir_col = ./mm_naive_direct $n $fA $fBc $fR 1 | Out-String
    $t_dir_col = "Err"
    if ($out_dir_col -match "Time\(s\):([\d\.]+)") { $t_dir_col = $Matches[1] }
    
    $report += "$n`t$t_orig`t`t$t_dir_row`t`t$t_dir_col"
}
$report += "`n"

# --- Inciso b ---
Write-Host "Ejecutando Inciso b..."
$report += "1.b. Multiplicacion de matrices C = A.A"
$report += "N`tEstrategia 1 (Row-Row)`tEstrategia 2 (Reorder+Col)"
$report += ("-" * 70)
foreach ($n in $SIZES) {
    $fA = "$MATRICES_DIR" + "A$n.m"
    $out_aa = ./mm_aa $n $fA | Out-String
    $t1 = "Err"; $t2 = "Err"
    if ($out_aa -match "Tiempo Estrategia 1: ([\d\.]+)") { $t1 = $Matches[1] }
    if ($out_aa -match "Tiempo Estrategia 2: ([\d\.]+)") { $t2 = $Matches[1] }
    $report += "$n`t$t1`t`t`t$t2"
}
$report += "`n"

# --- Inciso c ---
Write-Host "Ejecutando Inciso c..."
$report += "1.c. Algoritmo mmblk (Por bloques)"
$header = "N`t" + ($BLOCK_SIZES -join "`t")
$report += $header
$report += ("-" * 70)
foreach ($n in $SIZES) {
    $line = "$n"
    $fA = "$MATRICES_DIR" + "A$n.m"
    $fBc = "$MATRICES_DIR" + "B$n.m"
    $fR = "$MATRICES_DIR" + "R$n.m"
    foreach ($bs in $BLOCK_SIZES) {
        if ($n % $bs -ne 0) { $line += "`tN/A"; continue }
        $out_blk = ./mmblk $n $bs $fA $fBc $fR | Out-String
        $t_blk = "Err"
        if ($out_blk -match "Tiempo\(seg\): ([\d\.]+)") { $t_blk = $Matches[1] }
        $line += "`t$t_blk"
    }
    $report += $line
}
$report += "`n"

# --- Inciso d ---
Write-Host "Ejecutando Inciso d..."
$report += "1.d. Algoritmo mmblk_blas"
$report += $header
$report += ("-" * 70)
foreach ($n in $SIZES) {
    $line = "$n"
    $fA = "$MATRICES_DIR" + "A$n.m"
    $fBf = "$MATRICES_DIR" + "Bf$n.m"
    $fR = "$MATRICES_DIR" + "R$n.m"
    foreach ($bs in $BLOCK_SIZES) {
        if ($n % $bs -ne 0) { $line += "`tN/A"; continue }
        $out_blas = ./mmblk_blas $n $bs $fA $fBf $fR | Out-String
        $t_blas = "Err"
        if ($out_blas -match "Tiempo\(seg\): ([\d\.]+)") { $t_blas = $Matches[1] }
        $line += "`t$t_blas"
    }
    $report += $line
}
$report += "`n"

# --- Inciso e ---
Write-Host "Ejecutando Inciso e..."
$report += "1.e. Multiplicacion de matrices triangulares (MU, ML, UM, LM)"
$report += "N`tMU(F/O)`t`tML(F/O)`t`tUM(F/O)`t`tLM(F/O)"
$report += ("-" * 80)
foreach ($n in $SIZES) {
    $out_tri = ./mm_triangular $n | Out-String
    $dict = @{}
    foreach ($l in ($out_tri -split "`n")) {
        if ($l -match "Tiempo (\w+) (\w+): ([\d\.]+)") {
            $key = $Matches[1] + ($Matches[2].Substring(0,1))
            $dict[$key] = $Matches[3]
        }
    }
    $report += "$n`t$($dict['MUF'])/$($dict['MUO'])`t$($dict['MLF'])/$($dict['MLO'])`t$($dict['UMF'])/$($dict['UMO'])`t$($dict['LMF'])/$($dict['LMO'])"
}

$report | Out-File -FilePath $OUTPUT_FILE -Encoding utf8
Write-Host "Proceso completado. Resultados en $OUTPUT_FILE"
