| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` |  Deprecation -> Class UnitaryGate is deprecated | qrn_tax_ddbb-7a0f903f-15ca-44f5-a419-776beca27889 | qiskit.extensions.UnitaryGate | `from qiskit.quantum.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> Class ExtensionError is deprecated | qrn_tax_ddbb-c10a791d-cb18-4995-89ba-6feff423989c | qiskit.extensions.exceptions.ExtensionError | `from qiskit.exceptions import QiskitError` |
| 9 | `raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> Class ExtensionError is deprecated | qrn_tax_ddbb-c10a791d-cb18-4995-89ba-6feff423989c | qiskit.extensions.exceptions.ExtensionError | `raise QiskitError("La matriz debe ser cuadrada")` |
| 12 | `except ExtensionError as e:` | Deprecation -> Class ExtensionError is deprecated | qrn_tax_ddbb-c10a791d-cb18-4995-89ba-6feff423989c | qiskit.extensions.exceptions.ExtensionError | `except QiskitError as e:` |

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