| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> UnitaryGate moved to qiskit.circuit.library | IK | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> ExtensionError deprecated, use QiskitError | IK | ExtensionError | `from qiskit.exceptions import QiskitError` |
| 9 | `            raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> raise of ExtensionError; should use QiskitError | IK | ExtensionError | `            raise QiskitError("La matriz debe ser cuadrada")` |
| 11 | `        custom_gate = UnitaryGate(matrix)` | Updated -> UnitaryGate from qiskit.circuit.library | IK | UnitaryGate | `        custom_gate = UnitaryGate(matrix)` |
| 14 | `    except ExtensionError as e:` | Deprecation -> except ExtensionError; use QiskitError | IK | ExtensionError | `    except QiskitError as e:` |

```python
    from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
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