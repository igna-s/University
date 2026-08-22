| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> The qiskit.extensions module is now deprecated | cc691dc8-fc12-43ef-bc84-57c209f58c87 | 179 | qiskit.extensions.exceptions | `from qiskit.exceptions import QiskitError` |
| 8 | `raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> The qiskit.extensions module is now deprecated | cc691dc8-fc12-43ef-bc84-57c209f53c87 | 179 | ExtensionError | `raise QiskitError("La matriz debe ser cuadrada")` |
| 13 | `except ExtensionError as e:` | Deprecation -> The qiskit.extensions module is now deprecated | cc691dc8-fc12-43ef-bc84-57c209f53c87 | 179 | ExtensionError | `except QiskitError as e:` |


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