| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | internal | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | internal | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Deprecation of qiskit.extensions module | bc39cc74-3382-4b55-bc9c-c44558547f03 | internal | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 20 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> The Barrier class no longer accepts an integer for the number of qubits, use a list of qubits instead. | * | internal | Barrier | `qc.barrier(qr[0], qr[1], qr[2])` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize
from qiskit.circuit.library import Barrier
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

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```