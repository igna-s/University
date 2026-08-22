| Line | Code                                                           | Scenario                                                                                           | Reference                                          | Artifact             | Refactoring                                      |
|------|----------------------------------------------------------------|---------------------------------------------------------------------------------------------------|---------------------------------------------------|----------------------|-------------------------------------------------|
| 2    | `from qiskit.extensions import UnitaryGate`                  | Deprecation -> UnitaryGate class is deprecated.                                                  | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions    | `from qiskit.circuit.library import UnitaryGate` |
| 3    | `from qiskit.extensions.exceptions import ExtensionError`     | Deprecation -> ExtensionError class is deprecated.                                                | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions.exceptions | `from qiskit.exceptions import ExtensionError`      |
| 10   | `qc.append(custom_gate, [qubit])`                           | (optional) -> Change append method to include a circuit method instead.                          | IK                                                | QuantumCircuit       | `qc.append(custom_gate, [qubit])`              |

```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
from qiskit.exceptions import ExtensionError
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
```