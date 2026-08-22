| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 5 | from qiskit import extensions as ext | Removal -> extensions is removed in Qiskit 1.0.0 | qrn_tax_ddbb-ffd26ff0-2ab5-4735-9b9d-304fd76d952b | extensions |  |
| 15 | qc.prepare_state(psi, [qr[0]]) | Removal -> QuantumCircuit.prepare_state() removed; use initialize() instead | qrn_tax_ddbb-18eff8fd-2bc1-4f3e-86c2-6ebe97ed9867 | QuantumCircuit.prepare_state | qc.initialize(psi, [qr[0]]) |
| 17 | qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]]) | Removal -> extensions.Barrier is removed; use QuantumCircuit.barrier instead | qrn_tax_ddbb-bb6e413b-6c17-4b0b-9e25-e6f756959d9e | extensions.Barrier | qc.barrier(qr[0], qr[1], qr[2]) |

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