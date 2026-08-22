| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.extensions import HGate, XGate, Initialize | Deprecation -> The qiskit.extensions module is deprecated and the gates should be imported directly from qiskit.circuit.library; Initialize is now in qiskit.circuit.library.Initialize | qrn_notax_ddbb--cf5e0316-4a51-492d-8ece-3fb66a87e820 | qiskit.extensions | from qiskit.circuit.library import HGate, XGate, Initialize |
| 3 | from qiskit.extensions import Barrier | Deprecation -> The qiskit.extensions module is deprecated and the Barrier gate should be imported from qiskit.circuit | qrn_notax_ddbb--cf5e0316-4a51-492d-8ece-3fb66a87e820 | qiskit.extensions | from qiskit.circuit import Barrier |
| 4 | from qiskit.extensions import UnitaryGate | Deprecation -> The qiskit.extensions module is deprecated and the UnitaryGate should be imported from qiskit.circuit.library | qrn_notax_ddbb--cf5e0316-4a51-492d-8ece-3fb66a87e820 | qiskit.extensions | from qiskit.circuit.library import UnitaryGate |
| 15 | qc.append(Barrier(3), [qr[0], qr[1], qr[2]]) | Updated -> Barrier is generally added with qc.barrier(qr[0], qr[1], qr[2]) or qc.barrier(*qr) instead of qc.append(Barrier(3), ...) | IK | Barrier | qc.barrier(qr[0], qr[1], qr[2]) |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize, UnitaryGate
from qiskit.circuit import Barrier
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = UnitaryGate(custom_matrix, label="Custom")
qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
init_gate = Initialize(psi)
qc.append(init_gate, [qr[0]])

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```