| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions` module has been removed | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> `qiskit.extensions` module has been removed | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `qiskit.extensions` module has been removed | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 10 | `qc.append(HGate(), [qr[0]])` | Deprecation -> `QuantumCircuit.append` method does not automatically decompose gates anymore | qrn_tax_ddbb-7098e9a2-9721-4f10-9112-9c97b819f046 | QuantumCircuit.append | `qc.h(qr[0])` |
| 11 | `qc.append(XGate(), [qr[1]])` | Deprecation -> `QuantumCircuit.append` method does not automatically decompose gates anymore | qrn_tax_ddbb-7098e9a2-9721-4f10-9112-9c97b819f046 | QuantumCircuit.append | `qc.x(qr[1])` |
| 18 | `init_gate = Initialize(psi)` | Deprecation -> `qiskit.circuit.Initialize` is deprecated. Use the method on `QuantumCircuit` instead. | qrn_tax_ddbb-2f84b6f0-d996-48ee-a10c-f377a06ed6a2 | Initialize | |
| 19 | `qc.append(init_gate, [qr[0]])` | Deprecation -> `QuantumCircuit.append` method does not automatically decompose gates anymore | qrn_tax_ddbb-7098e9a2-9721-4f10-9112-9c97b819f046 | QuantumCircuit.append | `qc.initialize(psi, [qr[0]])` |
| 21 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `QuantumCircuit.append` method does not automatically decompose gates anymore | qrn_tax_ddbb-7098e9a2-9721-4f10-9112-9c97b819f046 | QuantumCircuit.append | `qc.barrier(qr[0], qr[1], qr[2])` |
| 22 | `print(qc.draw())` | Deprecation -> `QuantumCircuit.draw()` method `output` argument has new default value | qrn_tax_ddbb-e9f08687-f1c5-4422-b5e1-cf2846171542 | QuantumCircuit.draw | `print(qc.draw(output='text'))` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize
from qiskit.circuit.library import Barrier
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

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw(output='text'))
```