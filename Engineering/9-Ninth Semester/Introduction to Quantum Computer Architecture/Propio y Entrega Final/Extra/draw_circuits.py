import os
import sys

# Asegurar que se usa el entorno local
sys.path.append(os.getcwd())

from qiskit import QuantumCircuit
from nqueens_grover import diffuser, build_oracle, build_compute_only
from nqueens_qaoa import build_qaoa_circuit, build_qubo, qubo_to_ising

print("--- GENERANDO DIAGRAMAS DE CIRCUITOS CUÁNTICOS (N=4) ---")

# 1. Grover Diffuser
print("\n[1] GENERANDO DIFUSOR DE GROVER (8 qubits de estado)")
diff_circuit = diffuser(8)
diff_text = str(diff_circuit.draw(output='text'))
diff_text_unfolded = str(diff_circuit.draw(output='text', fold=-1))
print(diff_text[:2000]) # Mostrar una parte en consola

# 2. Porción del Oráculo de Grover (Compute conflict entre reina 0 y reina 1)
print("\n[2] GENERANDO PARTE DEL ORÁCULO DE GROVER (Compute conflicto Q0-Q1)")
# Vamos a construir un circuito pequeño de 4 qubits de estado (Q0 y Q1) y 1 flag
# para ilustrar cómo se marca un conflicto.
small_qc = QuantumCircuit(5) # 4 qubits estado (2 para Q0, 2 para Q1) + 1 flag
# Simular conflicto: ci==cj o abs(ci-cj) == 1
# Por ejemplo, para ci=0, cj=0 (misma columna)
# q0, q1 son Q0. q2, q3 son Q1. q4 es flag
# q0=0, q1=0  => aplicar X a ambos
small_qc.x(0)
small_qc.x(1)
small_qc.x(2)
small_qc.x(3)
small_qc.mcx([0, 1, 2, 3], 4)
small_qc.x(0)
small_qc.x(1)
small_qc.x(2)
small_qc.x(3)

small_text = str(small_qc.draw(output='text'))
small_text_unfolded = str(small_qc.draw(output='text', fold=-1))
print(small_text)

# 3. QAOA Circuit (p=1 para legibilidad)
print("\n[3] GENERANDO CIRCUITO QAOA (N=4, p=1 repetición)")
Q = build_qubo(4, penalty=6.0)
h, J, offset = qubo_to_ising(Q)
qaoa_qc, _, _ = build_qaoa_circuit(h, J, 16, reps=1)
# Quitar medición al final para ver solo la parte variacional limpia
qaoa_qc_no_meas = qaoa_qc.copy()
# remover la última instrucción si es una barrera y mediciones
# Para evitar complicaciones, dibujamos los primeros 20-30 gates del QAOA
qaoa_text = str(qaoa_qc.draw(output='text'))
qaoa_text_unfolded = str(qaoa_qc.draw(output='text', fold=-1))
print(qaoa_text[:2000])

# 4. Grover Complete Circuit (1 iteration for clarity and completeness)
print("\n[4] GENERANDO CIRCUITO GROVER COMPLETO PARA N=4 (1 iteración)")
oracle, state_reg, pair_flags, _ = build_oracle(4)
from qiskit import ClassicalRegister
creg = ClassicalRegister(8, "c")
grover_qc = QuantumCircuit(state_reg, pair_flags, creg)
grover_qc.h(state_reg)
grover_qc.compose(oracle, inplace=True)
diff = diffuser(8)
grover_qc.compose(diff, qubits=state_reg, inplace=True)
grover_qc.measure(state_reg, creg)

grover_qc_text = str(grover_qc.draw(output='text'))
grover_qc_text_unfolded = str(grover_qc.draw(output='text', fold=-1))
print(grover_qc_text[:2000])

# Guardar los diagramas en archivos de texto para el README
with open("grover_diffuser.txt", "w", encoding="utf-8") as f:
    f.write(diff_text)

with open("grover_diffuser_unfolded.txt", "w", encoding="utf-8") as f:
    f.write(diff_text_unfolded)

with open("grover_oracle_conflict.txt", "w", encoding="utf-8") as f:
    f.write(small_text)

with open("grover_oracle_conflict_unfolded.txt", "w", encoding="utf-8") as f:
    f.write(small_text_unfolded)

with open("qaoa_circuit_p1.txt", "w", encoding="utf-8") as f:
    f.write(qaoa_text)

with open("qaoa_circuit_p1_unfolded.txt", "w", encoding="utf-8") as f:
    f.write(qaoa_text_unfolded)

with open("grover_circuit_complete.txt", "w", encoding="utf-8") as f:
    f.write(grover_qc_text)

with open("grover_circuit_complete_unfolded.txt", "w", encoding="utf-8") as f:
    f.write(grover_qc_text_unfolded)

print("\n¡Archivos de texto generados con éxito!")
