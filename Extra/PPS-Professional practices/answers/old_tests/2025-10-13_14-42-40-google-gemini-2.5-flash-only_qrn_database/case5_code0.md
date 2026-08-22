| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | HGate | `from qiskit.circuit.library import HGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | XGate | `from qiskit.circuit.library import XGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | Initialize | `from qiskit.circuit.library import Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> The qiskit.extensions module is now deprecated. Barrier has been moved to qiskit.circuit | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | Barrier | `from qiskit.circuit import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize
from qiskit.circuit import Barrier
from qiskit.circuit.library import UnitaryGate
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

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```