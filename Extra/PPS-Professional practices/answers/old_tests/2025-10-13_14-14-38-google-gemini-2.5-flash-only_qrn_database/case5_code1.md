| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> The `qiskit.extensions` module is deprecated. Most objects have been moved to `qiskit.circuit.library`. | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | qiskit.extensions | |
| 20 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> The `qiskit.extensions` module is deprecated. Most objects have been moved to `qiskit.circuit.library`. | * | c4cd73f0-8f65-4176-a8da-ce2f599538b3 | ext.Barrier | `from qiskit.circuit.library import Barrier` and `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` |


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

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```