| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is deprecated. | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `HGate` | `from qiskit.circuit.library import HGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> The qiskit.extensions module is deprecated. | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `XGate` | `from qiskit.circuit.library import XGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> Initialize moved from qiskit.extensions to qiskit.circuit.library. | `cc691dc8-fc12-43ef-bc84-57c209f58c87` | `cc691dc8-fc12-43ef-bc84-57c209f58c87` | `Initialize` | `from qiskit.circuit.library import Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> The qiskit.extensions module is deprecated. Barrier is now in qiskit.circuit. | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `bc39cc74-3382-4b55-bc9c-c44558547f03` | `Barrier` | `from qiskit.circuit import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> UnitaryGate moved from qiskit.extensions to qiskit.circuit.library. | `cc691dc8-fc12-43ef-bc84-57c209f58c87` | `cc691dc8-fc12-43ef-bc84-57c209f58c87` | `UnitaryGate` | `from qiskit.circuit.library import UnitaryGate` |


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

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```