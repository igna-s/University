| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | qiskit.extensions.exceptions | `from qiskit.circuit.library.exceptions import CircuitLibraryError` |
| 9 | `raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | ExtensionError | `raise CircuitLibraryError("La matriz debe ser cuadrada")` |
| 11 | `custom_gate = UnitaryGate(matrix)` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | UnitaryGate | `custom_gate = UnitaryGate(matrix)` |
| 14 | `except ExtensionError as e:` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | 26 | ExtensionError | `except CircuitLibraryError as e:` |


```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
from qiskit.circuit.library.exceptions import CircuitLibraryError
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise CircuitLibraryError("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except CircuitLibraryError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```