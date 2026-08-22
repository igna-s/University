| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `import qiskit.extensions as ext` | Deprecation -> The qiskit.extensions module is now deprecated. Most objects have been moved to qiskit.circuit.library. | cc691dc8-fc12-43ef-bc84-57c209f58c87 | cc691dc8-fc12-43ef-bc84-57c209f58c87 | qiskit.extensions | |
| 16 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> qiskit.extensions.Barrier is deprecated and all support will be removed in Qiskit 1.0. | cc691dc8-fc12-43ef-bc84-57c209f58c87 | cc691dc8-fc12-43ef-bc84-57c209f58c87 | ext.Barrier | `qc.barrier(qr)` |


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

qc.barrier(qr)
print(qc.draw())
```