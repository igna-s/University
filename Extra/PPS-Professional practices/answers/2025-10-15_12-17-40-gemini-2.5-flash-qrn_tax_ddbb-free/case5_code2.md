| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Aer object deprecated | qrn_tax_ddbb--0771d384-706f-40c0-818d-20a4b728e9a2 | Aer | `from qiskit_aer import Aer` (though not used in refactored code) |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> execute() function deprecated | qrn_tax_ddbb--d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | execute | (removed, replaced by Statevector(qc)) |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Structural change -> Statevector simulator migration (optional) | qrn_tax_ddbb--09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | Statevector | `from qiskit.quantum_info import Pauli, state_fidelity, Statevector` |
| 16 | `simulator = Aer.get_backend('statevector_simulator')` | Structural change -> Statevector simulator migration | qrn_tax_ddbb--09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | Aer.get_backend('statevector_simulator') | (removed, replaced by Statevector(qc)) |
| 17 | `result = execute(qc, simulator).result()` | Structural change -> Statevector simulator migration | qrn_tax_ddbb--09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | execute(), result() | (removed, replaced by Statevector(qc)) |
| 18 | `statevector = result.get_statevector()` | Structural change -> Statevector simulator migration | qrn_tax_ddbb--09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | get_statevector() | (removed, replaced by Statevector(qc)) |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, state_fidelity, Statevector
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm

pauli_z = Pauli('Z').to_matrix()
pauli_x = Pauli('X').to_matrix()
hamiltonian = 0.5 * pauli_z + 0.3 * pauli_x

time = 1.0
evolution_matrix = expm(-1j * hamiltonian * time)
U, s, Vh = np.linalg.svd(evolution_matrix)
evolution_matrix = U @ Vh
qc = QuantumCircuit(1)
qc.h(0)
qc.unitary(Operator(evolution_matrix), [0])

statevector = Statevector(qc)

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```