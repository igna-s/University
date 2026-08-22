from qiskit import QuantumCircuit
from qiskit.extensions import UnitaryGate
from qiskit.extensions.exceptions import ExtensionError
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise ExtensionError("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except ExtensionError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)