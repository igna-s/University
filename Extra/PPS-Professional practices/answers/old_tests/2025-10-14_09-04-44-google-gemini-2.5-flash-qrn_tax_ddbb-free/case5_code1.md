| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> `qiskit.extensions` module is deprecated | Internal Knowledge | qiskit.extensions | |
| 15 | `qc.prepare_state(psi, [qr[0]])` | Deprecation -> The `QuantumCircuit.prepare_state` method is deprecated | Internal Knowledge | prepare_state | `qc.initialize(psi, [qr[0]])` |
| 17 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `Barrier` from `qiskit.extensions` is deprecated. | Internal Knowledge | ext.Barrier | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate
from qiskit.circuit import Gate, Barrier
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
qc.initialize(psi, [qr[0]])

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```