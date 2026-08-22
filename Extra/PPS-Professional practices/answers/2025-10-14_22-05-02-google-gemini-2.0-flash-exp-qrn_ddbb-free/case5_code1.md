| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.circuit import Gate` | Deprecation -> Class Gate deprecated | IK | qiskit.circuit.Gate | `from qiskit.primitives import ParametricGate` |
| 6 | `from qiskit import extensions as ext` | Deprecation -> Package qiskit.extensions deprecated | IK | qiskit.extensions |  |
| 20 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> Package qiskit.extensions deprecated | IK | qiskit.extensions | `qc.barrier(qr[0], qr[1], qr[2])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate
from qiskit.primitives import ParametricGate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = ParametricGate(name="Custom", num_qubits=1, params=[])
qc.append(custom_gate, [qr[2]])
qc.unitary(custom_matrix, [qr[2]], label="Custom")

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
qc.prepare_state(psi, [qr[0]])

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```