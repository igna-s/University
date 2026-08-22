| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.extensions import UnitaryGate | Deprecation -> The `qiskit.extensions` module is deprecated; objects including `UnitaryGate` moved to `qiskit.circuit.library` | qrn_tax_ddbb-25d237ef-d80c-4d14-a373-4f2bc5ec75ef | qiskit.extensions.UnitaryGate | from qiskit.circuit.library import UnitaryGate | 
| 3 | from qiskit.extensions.exceptions import ExtensionError | Deprecation -> The `qiskit.extensions` module, including exception classes, is deprecated and no longer exists | qrn_tax_ddbb-25d237ef-d80c-4d14-a373-4f2bc5ec75ef | qiskit.extensions.exceptions.ExtensionError |  | 
| 9 |             raise ExtensionError("La matriz debe ser cuadrada") | Deprecation -> The `ExtensionError` exception is no longer available in 1.0.0 | qrn_tax_ddbb-25d237ef-d80c-4d14-a373-4f2bc5ec75ef | ExtensionError | raise ValueError("La matriz debe ser cuadrada") | 
| 14 |     except ExtensionError as e: | Deprecation -> The `ExtensionError` exception is no longer available in 1.0.0 | qrn_tax_ddbb-25d237ef-d80c-4d14-a373-4f2bc5ec75ef | ExtensionError | except ValueError as e: | 


```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import UnitaryGate
import numpy as np

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise ValueError("La matriz debe ser cuadrada")
            
        custom_gate = UnitaryGate(matrix)
        qc.append(custom_gate, [qubit])
        
    except ValueError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```