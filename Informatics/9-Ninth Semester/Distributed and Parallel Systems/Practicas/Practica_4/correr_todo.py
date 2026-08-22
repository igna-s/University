import os
import subprocess
import sys

def run_cmd(cmd, f_out):
    print(f"Ejecutando: {cmd}")
    f_out.write(f"--- Ejecutando: {cmd} ---\n")
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        msg = f"Error al ejecutar: {cmd}\n{result.stderr}\n"
        print(msg)
        f_out.write(msg)
    else:
        print(result.stdout)
        f_out.write(result.stdout)
        f_out.write("\n")
    return result.stdout

def update_latex_with_results(results_text):
    latex_file = "respuestas.tex"
    if not os.path.exists(latex_file):
        return

    with open(latex_file, "r", encoding="utf-8") as f:
        content = f.read()

    # Si ya existe la seccion de resultados, la cortamos para reemplazarla
    if "\\section{Resultados de Ejecucion}" in content:
        content = content.split("\\section{Resultados de Ejecucion}")[0]
    else:
        content = content.replace("\\end{document}", "")

    latex_table = "\\section{Resultados de Ejecucion}\n"
    latex_table += "A continuacion se presentan los resultados de los benchmarks obtenidos en la corrida automatizada.\\\\ \\\\\n"
    latex_table += "\\begin{verbatim}\n"
    latex_table += results_text
    latex_table += "\\end{verbatim}\n\n"
    latex_table += "\\end{document}\n"

    with open(latex_file, "w", encoding="utf-8") as f:
        f.write(content + latex_table)

def main():
    print("=== Compilando Archivos ===")
    
    compilation_cmds = [
        "mpicc ej1_mpi_pthreads.c -o ej1_mpi_pthreads.exe -pthread",
        "mpicc ej1_mpi_openmp.c -o ej1_mpi_openmp.exe -fopenmp",
        "mpicc ej2_mpi_pthreads.c -o ej2_mpi_pthreads.exe -pthread",
        "mpicc ej2_mpi_openmp.c -o ej2_mpi_openmp.exe -fopenmp",
        "mpicc ej3_nreinas_hibrido.c -o ej3_nreinas_hibrido.exe -fopenmp",
        "nvcc ej4_cuda.cu -o ej4_cuda.exe",
        "nvcc ej5_cuda.cu -o ej5_cuda.exe",
        "nvcc ej6_nreinas_cuda.cu -o ej6_nreinas_cuda.exe"
    ]
    
    with open("resultados.txt", "w", encoding="utf-8") as f_out:
        f_out.write("=== Compilacion ===\n")
        for cmd in compilation_cmds:
            run_cmd(cmd, f_out)

        print("\n=== Ejecutando Benchmarks ===")
        f_out.write("\n=== Ejecucion de Benchmarks ===\n")
        
        N_values_matrix = [512, 1024, 2048]
        N_values_vector = [1000000, 5000000] 
        threads_per_block = [256, 512]
        
        num_procs = 2
        num_threads = 4
        
        all_stdout = ""
        
        # Ejercicio 1
        for n in N_values_matrix:
            all_stdout += run_cmd(f"mpiexec -n {num_procs} ./ej1_mpi_pthreads.exe {n} {num_threads}", f_out)
            all_stdout += run_cmd(f"mpiexec -n {num_procs} ./ej1_mpi_openmp.exe {n} {num_threads}", f_out)
            
        # Ejercicio 2
        for n in N_values_vector:
            all_stdout += run_cmd(f"mpiexec -n {num_procs} ./ej2_mpi_pthreads.exe {n} {num_threads}", f_out)
            all_stdout += run_cmd(f"mpiexec -n {num_procs} ./ej2_mpi_openmp.exe {n} {num_threads}", f_out)
            
        # Ejercicio 4
        for n in N_values_matrix:
            for tpb in threads_per_block:
                all_stdout += run_cmd(f"./ej4_cuda.exe {n} {tpb}", f_out)
                
        # Ejercicio 5
        for n in N_values_vector:
            for tpb in threads_per_block:
                all_stdout += run_cmd(f"./ej5_cuda.exe {n} {tpb}", f_out)

        # N-Reinas
        all_stdout += run_cmd(f"mpiexec -n {num_procs} ./ej3_nreinas_hibrido.exe 9 {num_threads}", f_out)
        all_stdout += run_cmd(f"./ej6_nreinas_cuda.exe 9", f_out)

    # Actualizamos el LaTeX con los resultados reales obtenidos de la corrida
    update_latex_with_results(all_stdout)
    
    print("\n=== Finalizado ===")
    print("Se guardaron los resultados en resultados.txt y se actualizaron en respuestas.tex")

if __name__ == "__main__":
    main()
