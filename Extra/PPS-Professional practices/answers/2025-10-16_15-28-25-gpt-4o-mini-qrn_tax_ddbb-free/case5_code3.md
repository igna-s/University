| Line | Code                                                              | Scenario                                                 | Reference                                                | Artifact                        | Refactoring                                                   |
| :--: | :--------------------------------------------------------------- | :------------------------------------------------------ | :------------------------------------------------------ | :----------------------------- | :------------------------------------------------------------ |
| 2    | `from qiskit.extensions import UnitaryGate`                     | Deprecation -> UnitaryGate class is deprecated          | qrn_tax_ddbb--50d189a0-2a11-41e3-95e1-80286df786a6     | qiskit.extensions              | `from qiskit.circuit.library import UnitaryGate`            |
| 3    | `from qiskit.extensions.exceptions import ExtensionError`       | Deprecation -> ExtensionError class is deprecated       | qrn_tax_ddbb--d9f84579-d58f-43da-a4e4-2a4e04dd79cd     | qiskit.extensions.exceptions   | `from qiskit.exceptions import ExtensionError`               |

```python
from qiskit import QuantumCircuit
import numpy as np
from qiskit.circuit.library import UnitaryGate
from qiskit.exceptions import ExtensionError

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