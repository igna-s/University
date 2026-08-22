| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `HGate`, `XGate`, `Initialize` from `qiskit.extensions` deprecated | qrn_tax_ddbb-04be4b7d-d39f-4b9a-95d4-b5ad5c04e0df | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 5 | `from qiskit.extensions import Barrier` | Deprecation -> `Barrier` from `qiskit.extensions` deprecated | qrn_tax_ddbb-5c074756-4c9b-41a1-84dc-83b2b30e4654 | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 6 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `UnitaryGate` from `qiskit.extensions` deprecated | qrn_tax_ddbb-9675eb28-7d2b-4e65-9c7e-ddacf44aec89 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 17 | `init_gate = Initialize(psi)` | Deprecation -> `Initialize` from `qiskit.extensions` deprecated | qrn_tax_ddbb-9f74e8f4-4305-41f1-8103-7e1aad604545 | qiskit.extensions | `init_gate = Initialize(psi)` |

```python
from qiskit import QuantumCircuit, QuantumRegister
from qiskit.circuit.library import HGate, XGate, Initialize, Barrier, UnitaryGate
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