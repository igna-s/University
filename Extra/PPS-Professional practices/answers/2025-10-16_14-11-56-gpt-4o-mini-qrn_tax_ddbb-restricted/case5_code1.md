| Line | Code                                                         | Scenario                                                                           | Reference                                       | Artifact                            | Refactoring                                                  |
| :--: | :---------------------------------------------------------- | :-------------------------------------------------------------------------------- | :--------------------------------------------- | :---------------------------------- | :---------------------------------------------------------- |
| 1    | `from qiskit import QuantumCircuit, QuantumRegister`       | Deprecation -> `QuantumRegister` has been deprecated                             | IK                                             | qiskit                             | `from qiskit import QuantumCircuit`                         |
| 2    | `from qiskit.circuit.library import HGate, XGate`          | Migration: `HGate` and `XGate` moved to qiskit.circuit.library                  | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | qiskit.circuit.library             | `from qiskit.circuit.library import HGate, XGate`          |
| 3    | `from qiskit.circuit import Gate`                           | Deprecation -> `Gate` has been deprecated                                         | IK                                             | qiskit.circuit                     | Remove line                                                  |
| 4    | `from qiskit import extensions as ext`                      | Deprecation -> The `extensions` module is deprecated                             | IK                                             | qiskit.extensions                  | `from qiskit.circuit.library import *`                      |
| 14   | `qc.prepare_state(psi, [qr[0]])`                           | Migration -> `prepare_state` function has been removed                            | IK                                             | QuantumCircuit                      | Remove line                                                  |
| 19   | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])`        | Deprecation -> `Barrier` has moved                                                  | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | qiskit.circuit                     | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])`             |

```python
from qiskit import QuantumCircuit
from qiskit.circuit.library import HGate, XGate
import numpy as np

qr = QuantumRegister(3)
qc = QuantumCircuit(qr)

qc.append(HGate(), [qr[0]])
qc.append(XGate(), [qr[1]])

custom_matrix = np.array([[0, 1], [1, 0]])
custom_gate = Gate(name="Custom", num_qubits=1, params=[])
qc.append(custom_gate, [qr[2]])
qc.unitary(custom_matrix, [qr[2]])

qc.append(Barrier(3), [qr[0], qr[1], qr[2]])
print(qc.draw())
```