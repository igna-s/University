$N = 1024
$MatricesDir = "..\Matrices"
$SourceDir = "..\Codigo_Fuente"
$OutputDir = "."

# Absolute paths are safer but let's use relative within the workspace
$A = "$MatricesDir\A$N.m"
$Bf = "$MatricesDir\Bf$N.m"
$B = "$MatricesDir\B$N.m"
$R = "$MatricesDir\R$N.m"

$ResultsFile = "results.txt"
"" | Out-File $ResultsFile

function Run-Bench {
    param(
        [string]$name,
        [string]$file,
        [string[]]$cmd_args
    )
    Write-Host "Benchmarking $name..."
    $exe = ".\$name.exe"
    
    # Compile - quote paths
    & gcc -o "$exe" "$file"
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Error compiling $file"
        return
    }
    
    # Run - quote exe path
    $out = & "$exe" @cmd_args
    $out | Out-File $ResultsFile -Append
    Write-Output $out
}

# (a) Naive, Direct, Col
Run-Bench -name "mm_naive" -file "$SourceDir\mm_naive.c" -cmd_args $N, $A, $Bf, $R
Run-Bench -name "mm_direct" -file ".\mm_direct.c" -cmd_args $N, $A, $Bf, $R
Run-Bench -name "mm_col" -file ".\mm_col.c" -cmd_args $N, $A, $B, $R

# (b) Squaring
Run-Bench -name "mm_aa" -file ".\mm_aa.c" -cmd_args $N, $A

# (c) Block
foreach ($bs in 16, 32, 64, 128) {
    Run-Bench -name "mmblk_$bs" -file "$SourceDir\mmblk.c" -cmd_args $N, $bs, $A, $B, $R
}

# (d) Block BLAS
foreach ($bs in 16, 32, 64, 128) {
    Run-Bench -name "mmblk_blas_$bs" -file "$SourceDir\mmblk_blas.c" -cmd_args $N, $bs, $A, $Bf, $R
}

# (e) Triangular
Run-Bench -name "triangular_matmul" -file ".\triangular_matmul.c" -cmd_args $N, $A
