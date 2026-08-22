| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> The qiskit.extensions module is now deprecated | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | qiskit.extensions.UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> The qiskit.extensions module is now deprecated | IK | qiskit.extensions.exceptions.ExtensionError | `from qiskit.exceptions import QiskitError` |
| 8 | `            raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> The qiskit.extensions module is now deprecated | IK | ExtensionError | `            raise QiskitError("La matriz debe ser cuadrada")` |
| 12 | `    except ExtensionError as e:` | Deprecation -> The qiskit.extensions module is now deprecated | IK | ExtensionError | `    except QiskitError as e:` |


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