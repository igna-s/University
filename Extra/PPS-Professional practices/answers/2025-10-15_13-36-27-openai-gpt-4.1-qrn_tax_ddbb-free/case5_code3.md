| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.extensions import UnitaryGate | Deprecation -> UnitaryGate moved to qiskit.circuit.library | qrn_tax_ddbb--5aa18b8b-c42f-40c2-bfec-0835974e5a97 | qiskit.extensions.UnitaryGate | from qiskit.circuit.library import UnitaryGate |
| 3 | from qiskit.extensions.exceptions import ExtensionError | Deprecation -> ExtensionError removed in qiskit 1.0.0 | qrn_tax_ddbb--386ea442-6a20-4ad5-bdf5-2671e2f2c5fa | qiskit.extensions.exceptions.ExtensionError | from qiskit.exceptions import QiskitError |
| 8 | raise ExtensionError("La matriz debe ser cuadrada") | Breaking Change -> ExtensionError removed, use QiskitError | qrn_tax_ddbb--386ea442-6a20-4ad5-bdf5-2671e2f2c5fa | ExtensionError | raise QiskitError("La matriz debe ser cuadrada") |
| 11 | except ExtensionError as e: | Breaking Change -> ExtensionError removed, use QiskitError | qrn_tax_ddbb--386ea442-6a20-4ad5-bdf5-2671e2f2c5fa | ExtensionError | except QiskitError as e: |

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