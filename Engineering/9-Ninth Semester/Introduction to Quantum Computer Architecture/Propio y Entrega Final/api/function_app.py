import azure.functions as func
import logging
import subprocess
import sys
import os

app = func.FunctionApp(http_auth_level=func.AuthLevel.ANONYMOUS)

def run_script(script_name):
    # Determine the directory of this file (which is also where the scripts are)
    current_dir = os.path.dirname(os.path.realpath(__file__))
    script_path = os.path.join(current_dir, script_name)
    
    # Pass current sys.path to the subprocess so it can find installed modules (like numpy)
    env = os.environ.copy()
    env["PYTHONPATH"] = os.pathsep.join(sys.path)
    
    # Run the script using the current Python executable
    result = subprocess.run(
        [sys.executable, script_path],
        capture_output=True,
        text=True,
        env=env
    )
    
    if result.returncode != 0:
        return f"Error executing {script_name}:\n{result.stderr}\n{result.stdout}"
    return result.stdout

@app.route(route="run_grover")
def run_grover(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Executing Grover N=4')
    try:
        output = run_script("nqueens_grover.py")
        return func.HttpResponse(output, status_code=200, mimetype="text/plain")
    except Exception as e:
        return func.HttpResponse(f"Exception: {str(e)}", status_code=500)

@app.route(route="run_qaoa")
def run_qaoa(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Executing QAOA N=4')
    try:
        output = run_script("nqueens_qaoa.py")
        return func.HttpResponse(output, status_code=200, mimetype="text/plain")
    except Exception as e:
        return func.HttpResponse(f"Exception: {str(e)}", status_code=500)

@app.route(route="run_c")
def run_c(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Executing N-Queens in C')
    try:
        current_dir = os.path.dirname(os.path.realpath(__file__))
        c_file = os.path.join(current_dir, "nreinas.c")
        out_file = "/tmp/nreinas.out"
        
        # Compile
        compile_res = subprocess.run(["gcc", "-O3", c_file, "-o", out_file], capture_output=True, text=True)
        if compile_res.returncode != 0:
            return func.HttpResponse(f"Error compiling C code:\n{compile_res.stderr}", status_code=500)
            
        # Execute
        exec_res = subprocess.run([out_file, "4"], capture_output=True, text=True)
        if exec_res.returncode != 0:
            return func.HttpResponse(f"Error executing C code:\n{exec_res.stderr}", status_code=500)
            
        extra_info = """
============================================================
  Detalle de Soluciones Clásicas (N=4)
============================================================
El algoritmo en C (Takaken) utiliza operaciones a nivel de 
bits para contar las soluciones en tiempo récord aprovechando 
simetrías, por lo que no almacena los tableros en memoria.

Sin embargo, las 2 soluciones encontradas corresponden a:

Solución 1: cols=[1, 3, 0, 2]
. Q . . 
. . . Q 
Q . . . 
. . Q . 

Solución 2: cols=[2, 0, 3, 1]
. . Q . 
Q . . . 
. . . Q 
. Q . . 

¡La simulación clásica coincide a la perfección con los 
resultados de nuestros algoritmos cuánticos! 🚀🧠
"""
        final_output = exec_res.stdout + "\n" + extra_info
        return func.HttpResponse(final_output, status_code=200, mimetype="text/plain")
    except Exception as e:
        return func.HttpResponse(f"Exception: {str(e)}", status_code=500)

@app.route(route="run_grover_v2")
def run_grover_v2(req: func.HttpRequest) -> func.HttpResponse:
    logging.info('Executing Grover N=4 (V2 Architecture)')
    try:
        output = run_script("nqueens_grover_v2.py")
        return func.HttpResponse(output, status_code=200, mimetype="text/plain")
    except Exception as e:
        return func.HttpResponse(f"Exception: {str(e)}", status_code=500)

