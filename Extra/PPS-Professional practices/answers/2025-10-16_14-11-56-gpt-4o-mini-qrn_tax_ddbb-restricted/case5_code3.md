| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> The UnitaryGate class has been moved to qiskit.circuit.library | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` | 
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> The ExtensionError class is removed from the extensions module | qrn_tax_ddbb-6ecf0d75-110b-4dc1-8d77-d73f6b1eadb5 | qiskit.extensions.exceptions | `# no update needed` | 
| 12 | `     custom_gate = UnitaryGate(matrix)` | Migration -> Use Operator from `qiskit.quantum_info` instead of UnitaryGate | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | UnitaryGate | `custom_gate = Operator(matrix)` | 

```python
from qiskit import QuantumCircuit
import numpy as np
from qiskit.quantum_info import Operator

def apply_custom_gate(qc, matrix, qubit):
    try:
        if matrix.shape[0] != matrix.shape[1]:
            raise RuntimeError("La matriz debe ser cuadrada")
            
        custom_gate = Operator(matrix)
        qc.append(custom_gate, [qubit])
        
    except RuntimeError as e:
        print(f"Error en extensión: {e}")

qc = QuantumCircuit(1)

print("\nMatriz no cuadrada...")
apply_custom_gate(qc, np.array([[1, 0, 0], [0, 1, 0]]), 0)
```