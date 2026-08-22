| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | from qiskit import extensions as ext | Deprecation -> The qiskit.extensions module is deprecated; objects have moved to qiskit.circuit.library | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.extensions | Remove import; use qiskit.circuit.library if needed |
| 14 | qc.prepare_state(psi, [qr[0]]) | Deprecation -> QuantumCircuit.prepare_state() is removed in 1.0.0 | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | QuantumCircuit.prepare_state | Use from qiskit.quantum_info import Statevector; Statevector(psi).evolve(qc) or UnitaryGate for initialization, or see migration guide |
| 16 | qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]]) | Deprecation -> Use of qiskit.extensions.Barrier is deprecated; use QuantumCircuit.barrier method | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | Barrier | qc.barrier(qr[0], qr[1], qr[2]) |


```python
from qiskit import QuantumCircuit, QuantumRegister
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

# Remove deprecated .prepare_state -- see Qiskit migration guidance for initializing states
# For single-qubit state psi, as a replacement, you might use Initialize if needed:
# from qiskit.circuit.library import Initialize
# init_gate = Initialize(psi)
# qc.append(init_gate, [qr[0]])

qc.barrier(qr[0], qr[1], qr[2])
print(qc.draw())
```