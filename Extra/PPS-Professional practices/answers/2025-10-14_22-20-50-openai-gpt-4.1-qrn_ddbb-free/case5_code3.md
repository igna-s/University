| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.extensions import UnitaryGate | Deprecation -> UnitaryGate import path deprecated | qrn_ddbb-fe204cee-41b2-4010-82d5-80e0d56bfae3 | qiskit.extensions.UnitaryGate | from qiskit.circuit.library import UnitaryGate |
| 3 | from qiskit.extensions.exceptions import ExtensionError | Deprecation -> ExtensionError import path deprecated | qrn_ddbb-fe204cee-41b2-4010-82d5-80e0d56bfae3 | qiskit.extensions.exceptions.ExtensionError |  |

```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise Exception("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except Exception as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```