| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Migration -> qiskit.extensions module removed | IK | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions import Barrier` | Migration -> qiskit.extensions module removed | IK | qiskit.extensions |  |
| 4 | `from qiskit.extensions import UnitaryGate` | Migration -> qiskit.extensions module removed | IK | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 10 | `qc.append(HGate(), [qr[0]])` | Migration -> Use built-in gate methods | IK | HGate | `qc.h(qr[0])` |
| 11 | `qc.append(XGate(), [qr[1]])` | Migration -> Use built-in gate methods | IK | XGate | `qc.x(qr[1])` |
| 18 | `init_gate = Initialize(psi)` | Migration -> Initialize gate removed, use qc.initialize | IK | Initialize |  |
| 19 | `qc.append(init_gate, [qr[0]])` | Migration -> Replace with qc.initialize | IK | Initialize | `qc.initialize(psi, qr[0])` |
| 21 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Migration -> Barrier removed, use qc.barrier | IK | Barrier | `qc.barrier([qr[0], qr[1], qr[2]])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import UnitaryGate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.h(qr[0])
qc.x(qr[1])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = UnitaryGate(custom_matrix, label="Custom")
qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
qc.initialize(psi, qr[0])

qc.barrier([qr[0], qr[1], qr[2]])
print(qc.draw())
```