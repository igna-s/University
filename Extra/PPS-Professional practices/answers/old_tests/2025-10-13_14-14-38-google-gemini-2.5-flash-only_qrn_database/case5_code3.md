| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library. | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> The qiskit.extensions module is now deprecated. Associated exceptions are likely moved or replaced. | * | Internal Knowledge | ExtensionError | `from qiskit.exceptions import QiskitError` |
| 9 | `raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> The qiskit.extensions.exceptions.ExtensionError class is deprecated. | * | Internal Knowledge | ExtensionError | `raise QiskitError("La matriz debe ser cuadrada")` |
| 11 | `except ExtensionError as e:` | Deprecation -> The qiskit.extensions.exceptions.ExtensionError class is deprecated. | * | Internal Knowledge | ExtensionError | `except QiskitError as e:` |


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