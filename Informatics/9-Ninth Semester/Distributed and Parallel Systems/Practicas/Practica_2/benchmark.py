import subprocess
import os
import sys

# Paths
BASE_DIR = r"D:\Concurrencia-UNLP"
P2_DIR = os.path.join(BASE_DIR, "Practica 2")
MAT_DIR = os.path.join(BASE_DIR, "Practica_1", "Matrices")

# Matrices (N=1024)
N_MAT = 1024
MAT_A = os.path.join(MAT_DIR, f"A{N_MAT}.m")
# Based on tests:
# - R1024.m matches A*(Bf) when Bf is row-major (which is A*B_orig if Bf is Transpose)
# - mmblk matches R1024.m when using B1024.m (Original)
MAT_B = os.path.join(MAT_DIR, f"Bf{N_MAT}.m") 
MAT_B_ORIG = os.path.join(MAT_DIR, f"B{N_MAT}.m")
MAT_A_SQ = os.path.join(MAT_DIR, f"A_sq_{N_MAT}.m")
MAT_R = os.path.join(MAT_DIR, f"R{N_MAT}.m")

THREADS = [1, 2, 4, 8]
BS = 64

def run_cmd(cmd):
    print(f"Exec: {' '.join(cmd)}")
    res = subprocess.run(cmd, capture_output=True, text=True)
    if res.returncode != 0:
        print(f"Error: {res.stderr}")
    return res.stdout

def compile_all():
    print("--- Compiling (PDF Rules) ---")
    files = [f for f in os.listdir(P2_DIR) if f.endswith(".c")]
    for f in files:
        exe = f.replace(".c", ".exe")
        target = os.path.join(P2_DIR, exe)
        src = os.path.join(P2_DIR, f)
        
        if "openmp" in f:
            # gcc -fopenmp -O2 -o <ejecutable> <fuente>
            cmd = ["gcc", "-fopenmp", "-O2", "-o", target, src, "-lm"]
        else:
            # gcc -pthread -O2 -o <ejecutable> <fuente>
            cmd = ["gcc", "-pthread", "-O2", "-o", target, src, "-lm"]
        
        run_cmd(cmd)

def run_benchmarks():
    print("--- Running Benchmarks ---")
    results_path = os.path.join(P2_DIR, "benchmark_results.txt")
    with open(results_path, "w") as out_file:
        out_file.write("RESULTADOS PRÁCTICA 2\n")
        out_file.write("=====================\n\n")

        # 1. MM Naive
        for impl in ["mm_naive_pthreads.exe", "mm_naive_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), MAT_A, MAT_B, MAT_R])
                out_file.write(res + "\n")

        # 2. MM SQ (A*A)
        for impl in ["mm_sq_pthreads.exe", "mm_sq_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), MAT_A, MAT_A_SQ])
                out_file.write(res + "\n")

        # 3. MM BLK (blkmul computes A*B^T; with B_orig input gives A*B_orig^T = A*Bf = R)
        for impl in ["mmblk_pthreads.exe", "mmblk_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), str(BS), MAT_A, MAT_B_ORIG, MAT_R])
                out_file.write(res + "\n")

        # 3b. MM BLK BLAS (reorders B block locally; computes standard A*B; uses Bf so A*Bf = R)
        for impl in ["mmblk_blas_pthreads.exe", "mmblk_blas_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), str(BS), MAT_A, MAT_B, MAT_R])
                out_file.write(res + "\n")

        # 4. Stats
        for impl in ["stats_pthreads.exe", "stats_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), MAT_A])
                out_file.write(res + "\n")

        # 5. Transpose
        for impl in ["transpose_pthreads.exe", "transpose_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), str(N_MAT), str(t), MAT_A])
                out_file.write(res + "\n")

        # 6. N-Queens (N=13)
        for impl in ["nreinas_pthreads.exe", "nreinas_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), "13", str(t)])
                out_file.write(res + "\n")

        # 7. Merge Sort (N=1,000,000)
        for impl in ["merge_pthreads.exe", "merge_openmp.exe"]:
            for t in THREADS:
                res = run_cmd([os.path.join(P2_DIR, impl), "1000000", str(t)])
                out_file.write(res + "\n")

if __name__ == "__main__":
    compile_all()
    run_benchmarks()
    print(f"\nBenchmarking finished. Results in {P2_DIR}\\benchmark_results.txt")
