$ResultsFile = "fib_results.txt"
"" | Out-File $ResultsFile
gcc -o fib.exe fib.c
if ($LASTEXITCODE -ne 0) { throw "Error compiling fib.c" }

0, 10, 20, 30, 40, 42, 45 | ForEach-Object {
    Write-Host "Running for N=$_..."
    $out = .\fib.exe $_
    $out | Out-File $ResultsFile -Append
    Write-Output $out
}

Write-Host "Calculating N=50 (This will take a moment)..."
$out = .\fib.exe 50
$out | Out-File $ResultsFile -Append
Write-Output $out
