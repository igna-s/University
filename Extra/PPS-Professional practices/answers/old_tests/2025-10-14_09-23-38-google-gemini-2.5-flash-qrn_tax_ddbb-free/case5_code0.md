| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> Modules in qiskit.extensions are deprecated. | qrn_tax_ddbb-b44c | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate` |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions.Initialize` is deprecated. | qrn_tax_ddbb-871f | Initialize | |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> Modules in qiskit.extensions are deprecated. | qrn_tax_ddbb-b44c | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> Modules in qiskit.extensions are deprecated. | qrn_tax_ddbb-b44c | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 10 | `qc.append(HGate(), [qr[0]])` | Deprecation -> Direct instantiation of `HGate` and appending is deprecated. | qrn_tax_ddbb-a790 | HGate | `qc.h(qr[0])` |
| 11 | `qc.append(XGate(), [qr[1]])` | Deprecation -> Direct instantiation of `XGate` and appending is deprecated. | qrn_tax_ddbb-3d44 | XGate | `qc.x(qr[1])` |
| 17 | `init_gate = Initialize(psi)` | Deprecation -> `Initialize` class is deprecated. | qrn_tax_ddbb-871f | Initialize | |
| 18 | `qc.append(init_gate, [qr[0]])` | Deprecation -> `QuantumCircuit.append` with an `Initialize` gate is deprecated. | qrn_tax_ddbb-871f | qc.append | `qc.initialize(psi, [qr[0]])` |
| 20 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> Direct instantiation of `Barrier` and appending is deprecated. | qrn_tax_ddbb-2647 | Barrier | `qc.barrier(qr)` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Barrier, UnitaryGate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.h(qr[0])
qc.x(qr[1])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = UnitaryGate(custom_matrix, label="Custom")
qc.append(custom_gate, [qr[2]])

psi = [1/np.sqrt(2), 1/np.sqrt(2)]
qc.initialize(psi, [qr[0]])

qc.barrier(qr)
print(qc.draw())
```