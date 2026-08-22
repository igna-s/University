| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.extensions import HGate, XGate, Initialize | Deprecation -> qiskit.extensions module deprecated, gates moved to qiskit.circuit.library (HGate, XGate) and qiskit.circuit (Initialize) | qrn_tax_ddbb--72c1e213-d3ea-4dc7-b348-0b7bed1cfcd3 | qiskit.extensions | from qiskit.circuit.library import HGate, XGate; from qiskit.circuit import Initialize |
| 3 | from qiskit.extensions import Barrier | Deprecation -> qiskit.extensions module deprecated, Barrier moved to qiskit.circuit | qrn_tax_ddbb--93528694-0b38-4c59-89b2-20844668d017 | qiskit.extensions.Barrier | from qiskit.circuit import Barrier |
| 4 | from qiskit.extensions import UnitaryGate | Deprecation -> qiskit.extensions module deprecated, UnitaryGate moved to qiskit.circuit | qrn_tax_ddbb--c05aac53-cf2d-4b95-bb30-a074d091909f | qiskit.extensions.UnitaryGate | from qiskit.circuit import UnitaryGate |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate
from qiskit.circuit import Initialize, Barrier, UnitaryGate
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

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```