| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | Aer | `from qiskit import QuantumCircuit` |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Structural change -> Migration: Statevector simulator | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | Aer, statevector_simulator | (Replaced by `statevector = Statevector(qc)`) |
| 20 | `result = execute(qc, simulator).result()` | Structural change -> Migration: Statevector simulator | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | execute | (Replaced by `statevector = Statevector(qc)`) |


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