| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit import QuantumCircuit, QuantumRegister` | Updated -> Legacy import qiskit module | IK | qiskit | `from qiskit import QuantumCircuit, QuantumRegister` |
| 3 | `from qiskit.circuit.library import HGate, XGate` | Deprecation -> Qiskit.extensions module is deprecated | IK | qiskit.extensions | `from qiskit.circuit.library import H, X` |
| 5 | `custom_gate = Gate(name="Custom", num_qubits=1, params=[])` | Deprecation -> Gate class deprecated in favor of Circuit methods | IK | qiskit.circuit | `# custom_gate holds no valid replacement` |
| 9 | `qc.prepare_state(psi, [qr[0]])` | Deprecation -> prepare_state() function is deprecated | IK | qiskit.circuit | `# qc.prepare_state holds no valid replacement` | 
| 12 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> The extensions module is deprecated | IK | qiskit.extensions | `qc.barrier(qr[0], qr[1], qr[2])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import H, X
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(H(), [qr[0]])
qc.append(X(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
qc.unitary(custom_matrix, [qr[2]], label="Custom")

qc.append(qc.barrier(qr[0], qr[1], qr[2]))
print(qc.draw())
```