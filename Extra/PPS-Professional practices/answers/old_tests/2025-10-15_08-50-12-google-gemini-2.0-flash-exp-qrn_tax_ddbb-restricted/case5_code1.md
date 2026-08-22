| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> The qiskit.extensions module is deprecated and will be removed in a future release. Instead, import the gate or instruction directly from qiskit.circuit.library or qiskit.opflow. | qrn_tax_ddbb-e9969a7a-741c-4594-9983-9b9959a9817f | qiskit.extensions |  |
| 19 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> The qiskit.extensions module is deprecated and will be removed in a future release. Instead, import the gate or instruction directly from qiskit.circuit.library or qiskit.opflow. | qrn_tax_ddbb-e9969a7a-741c-4594-9983-9b9959a9817f | qiskit.extensions | `from qiskit.circuit.library import Barrier`<br>`qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` |

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