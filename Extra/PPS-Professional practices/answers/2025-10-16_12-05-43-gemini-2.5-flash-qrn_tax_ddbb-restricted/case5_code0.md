| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions` module moved | qrn_tax_ddbb-5c799a4e-1517-4fc3-a212-321a97d98342 | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> `qiskit.extensions` module moved | qrn_tax_ddbb-5c799a4e-1517-4fc3-a212-321a97d98342 | qiskit.extensions | `from qiskit.circuit import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `qiskit.extensions` module moved | qrn_tax_ddbb-5c799a4e-1517-4fc3-a212-321a97d98342 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 9 | `qc.append(HGate(), [qr[0]])` | Deprecation -> `QuantumCircuit.append` method now accepts gate objects directly | qrn_tax_ddbb-f1a580e0-8452-4427-a006-218209802092 | QuantumCircuit.append | `qc.h(qr[0])` |
| 10 | `qc.append(XGate(), [qr[1]])` | Deprecation -> `QuantumCircuit.append` method now accepts gate objects directly | qrn_tax_ddbb-f1a580e0-8452-4427-a006-218209802092 | QuantumCircuit.append | `qc.x(qr[1])` |
| 17 | `init_gate = Initialize(psi)` | Deprecation -> `Initialize` no longer directly instantiates the gate | qrn_tax_ddbb-8d2645e9-d922-4a0b-93f0-410a5624cf5b | Initialize | `qc.initialize(psi, [qr[0]])` |
| 18 | `qc.append(init_gate, [qr[0]])` | Deprecation -> `Initialize` is applied directly to the circuit | qrn_tax_ddbb-8d2645e9-d922-4a0b-93f0-410a5624cf5b | QuantumCircuit.append | |
| 20 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `QuantumCircuit.append` method now accepts gate objects directly | qrn_tax_ddbb-f1a580e0-8452-4427-a006-218209802092 | QuantumCircuit.append | `qc.barrier(qr)` |


```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize
from qiskit.circuit import Barrier
from qiskit.circuit.library import UnitaryGate
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