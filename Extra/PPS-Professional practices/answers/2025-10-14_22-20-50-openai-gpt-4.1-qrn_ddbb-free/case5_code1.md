| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | from qiskit import extensions as ext | Deprecation -> The 'extensions' module is deprecated | qrn_ddbb-3bwgyk1l5h0hgrd6xw7doowflosm | qiskit.extensions |  |
| 17 | qc.prepare_state(psi, [qr[0]]) | Removal -> The 'prepare_state' method has been removed, use 'initialize' instead | qrn_ddbb-92dnsds505yjh0b2smr8smxg4b83 | QuantumCircuit.prepare_state | qc.initialize(psi, [qr[0]]) |
| 19 | qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]]) | Removal -> 'Barrier' should be used from circuit library, not 'extensions' | qrn_ddbb-9ks603ofmzbjzetls7796199n95l | Barrier | qc.barrier(qr[0], qr[1], qr[2]) |

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
qc.initialize(psi, [qr[0]])

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```