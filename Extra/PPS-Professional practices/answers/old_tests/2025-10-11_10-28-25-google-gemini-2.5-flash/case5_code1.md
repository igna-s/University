| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `import qiskit.extensions as ext` | Deprecation -> `qiskit.extensions` module is deprecated | 26 | bc39cc74-3382-4b55-bc9c-c44558547f03 | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 20 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `qiskit.extensions` module is deprecated. Barrier has been moved to `qiskit.circuit.library` | cc691dc8-fc12-43ef-bc84-57c209f58c87 | cc691dc8-fc12-43ef-bc84-57c209f58c87 | ext.Barrier | `qc.barrier(qr[0], qr[1], qr[2])` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Barrier
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

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```