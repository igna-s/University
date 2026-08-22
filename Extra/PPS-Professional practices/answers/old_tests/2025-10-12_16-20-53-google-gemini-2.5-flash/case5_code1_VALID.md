| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> qiskit.extensions module deprecated | 24 | ad60c4b9-2085-4e56-857a-d06309e67cf9 | qiskit.extensions | |
| 17 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> The qiskit.extensions module is now deprecated | 24 | ad60c4b9-2085-4e56-857a-d06309e67cf9 | ext.Barrier | `qc.barrier(3)` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate
from qiskit.circuit import Gate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = Gate(name="Custom", num_qubits=1, params=[])
qc.append(custom_gate, [qr[2]])
qc.unitary(custom_matrix, [qr[2]], label="Custom")

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
qc.prepare_state(psi, [qr[0]])

qc.barrier(3)
print(qc.draw())
```