| Line | Code                                                     | Scenario                                                                                      | Reference                                            | Artifact                       | Refactoring                                         |
| :--: | :----------------------------------------------------- | :------------------------------------------------------------------------------------------ | :-------------------------------------------------- | :------------------------------ | :------------------------------------------------- |
| 2    | `from qiskit import QuantumCircuit, QuantumRegister`   | Deprecation -> QuantumRegister class is deprecated                                         | IK                                                  | qiskit.quantum_info            | `from qiskit import QuantumCircuit`                 |
| 3    | `from qiskit.circuit.library import HGate, XGate`      | Updated -> XGate, HGate moved to qiskit.circuit.library                                   | qrn_notax_ddbb-5d0341add-eea1-4b5a-8918-4b9e7c0650a7 | qiskit.circuit.library         | `from qiskit.circuit.library import HGate, XGate`  |
| 4    | `from qiskit.circuit import Gate`                       | Updated -> Gate moved to qiskit.circuit.library                                            | qrn_notax_ddbb-240019ec-593a-4635-ab87-b7ec3b54d72f | qiskit.circuit                 | `from qiskit.circuit import Gate`                  |
| 5    | `from qiskit import extensions as ext`                  | Deprecation -> qiskit.extensions module is deprecated                                       | IK                                                  | qiskit.extensions               | Keep empty                                         |
| 8    | `qc.prepare_state(psi, [qr[0]])`                       | Deprecation -> prepare_state() method is deprecated                                         | IK                                                  | QuantumCircuit                  | `qc.initialize(psi, [qr[0]])`                       |
| 12   | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])`    | Updated -> Barrier moved to qiskit.circuit library                                          | qrn_notax_ddbb-3520306e-45b8-4f06-9b39-3f3e9ef2a641 | qiskit.circuit.library         | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])`    |

```python
from qiskit import QuantumCircuit
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

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```