| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> HGate moved to qiskit.circuit.library | * | Internal Knowledge | HGate | `from qiskit.circuit.library import HGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> XGate moved to qiskit.circuit.library | * | Internal Knowledge | XGate | `from qiskit.circuit.library import XGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> Initialize moved to qiskit.circuit.library | * | Internal Knowledge | Initialize | `from qiskit.circuit.library import Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> Barrier moved to qiskit.circuit | * | Internal Knowledge | Barrier | (remove import; use qc.barrier instead) |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> UnitaryGate moved to qiskit.circuit.library | * | Internal Knowledge | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 21 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Update -> replace Barrier append with qc.barrier | * | Internal Knowledge | Barrier | `qc.barrier([qr[0], qr[1], qr[2]])` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize, UnitaryGate
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
