| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.extensions import UnitaryGate | Deprecation -> qiskit.extensions module is deprecated; UnitaryGate moved to qiskit.circuit.library | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | UnitaryGate | from qiskit.circuit.library import UnitaryGate |
| 3 | from qiskit.extensions.exceptions import ExtensionError | Deprecation -> qiskit.extensions.exceptions is deprecated and removed | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | ExtensionError |  |
| 9 | def apply_custom_gate(qc, matrix, qubit): | Deprecation -> ExtensionError exception is removed; replace with a built-in exception | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | ExtensionError | def apply_custom_gate(qc, matrix, qubit): |
| 12 | raise ExtensionError("La matriz debe ser cuadrada") | Deprecation -> ExtensionError exception is removed; replace with ValueError or similar | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | ExtensionError | raise ValueError("La matriz debe ser cuadrada") |
| 18 | except ExtensionError as e: | Deprecation -> ExtensionError exception is removed; replace with ValueError or similar | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | ExtensionError | except ValueError as e: |


```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise ValueError("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except ValueError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```