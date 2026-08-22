| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is deprecated, objects moved to qiskit.circuit.library | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> Barrier moved to qiskit.circuit | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions | `from qiskit.circuit import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Unitary adanya moved to qiskit.circuit.library | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 21 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | API change -> Barrier constructor signature changed (optional) | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | Barrier | `qc.barrier([qr[0], qr[1], qr[2]])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize, UnitaryGate
from qiskit.circuit import Barrier
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = UnitaryGate(custom_matrix, label="Custom")
qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
init_gate = Initialize(psi)
qc.append(init_gate, [qr[0]])

qc.barrier([qr[0], qr[1], qr[2]])
print(qc.draw())
```
