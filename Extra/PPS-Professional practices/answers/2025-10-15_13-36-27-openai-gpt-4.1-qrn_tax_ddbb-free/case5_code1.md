| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | `from qiskit import extensions as ext` | Deprecation -> qiskit.extensions module is removed in 1.0.0 | qrn_tax_ddbb--d7d30b42-7ece-42c8-ac7e-c18c9a6d13ac | qiskit.extensions |  |
| 15 | `qc.prepare_state(psi, [qr[0]])` | Removal -> QuantumCircuit.prepare_state() has been removed; use initialize() instead | qrn_tax_ddbb--924bb317-072e-43c1-ac4f-44fec55e75a3 | QuantumCircuit.prepare_state | `qc.initialize(psi, [qr[0]])` |
| 17 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> ext.Barrier replaced by QuantumCircuit.barrier() method | qrn_tax_ddbb--d7d30b42-7ece-42c8-ac7e-c18c9a6d13ac | ext.Barrier | `qc.barrier(qr[0], qr[1], qr[2])` |

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