| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The Aer module import is deprecated, use qiskit_aer instead | qrn_tax_ddbb-77cf2bb9-6b83-40bc-8e63-bb8bfd5d9fc9 | qiskit.Aer | `from qiskit_aer import Aer` |
| 14 | `from qiskit.quantum_info import Pauli, state_fidelity` | Updated -> The state_fidelity function has been updated | qrn_tax_ddbb-99ca98a9-2c4c-4a6c-bc3e-7c9109e5e12c | qiskit.quantum_info | `from qiskit.quantum_info import Statevector` |
| 19 | `evolution_matrix = expm(-1j * hamiltonian * time)` | Deprecation -> expm function requires specific import | qrn_tax_ddbb-3b14a864-11b2-4902-9ff0-313f34fd405c | scipy.linalg | `from scipy.linalg import expm` |
| 22 | `U, s, Vh = np.linalg.svd(evolution_matrix)` | Structural change -> Using singular value decomposition | qrn_tax_ddbb-ebf5c48e-abd7-48ae-9287-630421c346b0 | np.linalg |  |
| 38 | `simulator = Aer.get_backend('statevector_simulator')` | Migration -> Statevector simulator has changed to BasicProvider | qrn_tax_ddbb-76c54e44-0e79-4df7-9173-2ea7c499ef4d | backend | `from qiskit.providers.basic_provider import BasicProvider; simulator = BasicProvider().get_backend('basic_simulator')` |
| 39 | `result = execute(qc, simulator).result()` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb-aad3c67b-57df-4e67-b476-75ed6d5327b8 | qiskit.execute | `new_circuit = transpile(qc, simulator); result = backend.run(new_circuit).result()` |
| 41 | `statevector = result.get_statevector()` | Updated -> get_statevector has been replaced with Statevector | qrn_tax_ddbb-59ec74fb-6ec5-4d5f-b287-40331a73a77e | result | `statevector = Statevector(qc)` |
| 43 | `fidelity = state_fidelity(statevector, target_state)` | Deprecation -> state_fidelity requires explicit conversion using SparsePauliOp | qrn_tax_ddbb-0b31f1c1-5b06-4f91-ba09-17a37b0f0ccc | qiskit.quantum_info | `fidelity = state_fidelity(SparsePauliOp(statevector), SparsePauliOp(target_state))` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.quantum_info import Statevector, Operator
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

simulator = Aer.get_backend('statevector_simulator')
result = backend.run(transpile(qc, simulator)).result()
statevector = Statevector(qc)

target_state = np.array([0, 1])
fidelity = state_fidelity(SparsePauliOp(statevector), SparsePauliOp(target_state))
print(f"Fidelity: {fidelity:.4f}")
```