| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Class UnitaryGate is deprecated | qrn_ddbb-8a7a71f5042846128f4bf1649ca4234a | qiskit.extensions.UnitaryGate | `from qiskit.quantum.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> Class ExtensionError is deprecated | qrn_ddbb-2696c95699ce45c886137a0b9c716ef5 | qiskit.extensions.exceptions.ExtensionError | `from qiskit.exceptions import QiskitError` |

```python
from qiskit import QuantumCircuit
from qiskit.quantum.library import UnitaryGate
from qiskit.exceptions import QiskitError
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise QiskitError("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except QiskitError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```