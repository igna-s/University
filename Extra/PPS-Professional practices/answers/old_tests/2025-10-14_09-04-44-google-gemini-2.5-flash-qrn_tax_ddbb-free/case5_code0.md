| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions` module is deprecated. Use `QuantumCircuit` methods or import from `qiskit.circuit.library`. | Internal Knowledge | `HGate`, `XGate`, `Initialize` | |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> `qiskit.extensions` module is deprecated. Use `QuantumCircuit.barrier()` or import from `qiskit.circuit.library`. | Internal Knowledge | `Barrier` | |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `qiskit.extensions` module is deprecated. Import `UnitaryGate` from `qiskit.circuit.library`. | Internal Knowledge | `UnitaryGate` | `from qiskit.circuit.library import UnitaryGate` |
| 10 | `qc.append(HGate(), [qr[0]])` | Deprecation -> `HGate` object from `qiskit.extensions` is deprecated for direct `append`. Use `QuantumCircuit.h()` method. | Internal Knowledge | `HGate` | `qc.h(qr[0])` |
| 11 | `qc.append(XGate(), [qr[1]])` | Deprecation -> `XGate` object from `qiskit.extensions` is deprecated for direct `append`. Use `QuantumCircuit.x()` method. | Internal Knowledge | `XGate` | `qc.x(qr[1])` |
| 17 | `init_gate = Initialize(psi)` | Deprecation -> `Initialize` from `qiskit.extensions` is deprecated. Use `QuantumCircuit.initialize()` method directly. | Internal Knowledge | `Initialize` | `qc.initialize(psi, [qr[0]])` |
| 18 | `qc.append(init_gate, [qr[0]])` | Deprecation -> `Initialize` object usage with `append` is deprecated. Combined with previous refactoring. | Internal Knowledge | `init_gate` | |
| 20 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `Barrier` object from `qiskit.extensions` is deprecated for direct `append`. Use `QuantumCircuit.barrier()` method. | Internal Knowledge | `Barrier` | `qc.barrier(qr)` |


```python
from qiskit import QuantumCircuit, QuantumRegister
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