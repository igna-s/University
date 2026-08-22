| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:----:|------|----------|-----------|----------|-------------|
| 4 | `from qiskit import extensions as ext` | Deprecation -> extensions module is removed | IK | extensions | `from qiskit.circuit import Barrier` |
| 16 | `qc.unitary(custom_matrix, [qr[2]], label="Custom")` | Deprecation -> QuantumCircuit.unitary() removed | IK | unitary | `qc.append(qiskit.circuit.library.UnitaryGate(custom_matrix, label="Custom"), [qr[2]])` |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> Barrier moved to qiskit.circuit | IK | Barrier | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate
from qiskit.circuit import Gate
from qiskit.circuit import Barrier
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = Gate(name="Custom", num_qubits=1, params=[])
qc.append(custom_gate, [qr[2]])
qc.append(qiskit.circuit.library.UnitaryGate(custom_matrix, label="Custom"), [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
qc.prepare_state(psi, [qr[0]])

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```