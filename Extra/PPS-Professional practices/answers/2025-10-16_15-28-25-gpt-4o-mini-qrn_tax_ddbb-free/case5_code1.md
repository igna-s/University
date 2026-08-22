| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import extensions as ext` | Deprecation -> qiskit.extensions module is deprecated | qrn_tax_ddbb--27ebf47d-f549-4a4b-ad7c-72ec480eb99d | qiskit.extensions | `from qiskit.circuit.library import *` |
| 18 | `qc.prepare_state(psi, [qr[0]])` | Deprecation -> prepare_state method is deprecated | qrn_tax_ddbb--5a6d002f-95c2-4460-89f5-305ef4b7d4f3 | QuantumCircuit | |
| 21 | `qc.unitary(custom_matrix, [qr[2]], label="Custom")` | Deprecation -> unitary method is deprecated | qrn_tax_ddbb--5a6d002f-95c2-4460-89f5-305ef4b7d4f3 | QuantumCircuit | |
| 22 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> Barrier class is deprecated | qrn_tax_ddbb--27ebf47d-f549-4a4b-ad7c-72ec480eb99d | ext.Barrier | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` |
| 25 | `from qiskit.circuit.library import HGate, XGate` | Structural change -> Use `qiskit.circuit.library` instead of `qiskit.extensions` | IK | HGate, XGate | |
| 28 | `qc.append(HGate(), [qr[0]])` | Structural change -> Use `HGate` from `qiskit.circuit.library` | IK | HGate | |
| 29 | `qc.append(XGate(), [qr[1]])` | Structural change -> Use `XGate` from `qiskit.circuit.library` | IK | XGate | |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Barrier
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = Gate(name="Custom", num_qubits=1, params=[])

qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```