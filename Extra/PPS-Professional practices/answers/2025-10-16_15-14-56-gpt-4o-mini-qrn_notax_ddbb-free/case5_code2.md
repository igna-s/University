| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The execute() function is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit | `from qiskit import QuantumCircuit`\n`from qiskit_aer import Aer` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Updated -> state_fidelity has been moved to qiskit.quantum_info | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit.quantum_info | `from qiskit.quantum_info import Statevector, Pauli` |
| 3 | `from qiskit.quantum_info.operators import Operator` | Updated -> Operator has been moved | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.quantum_info.operators | `from qiskit.quantum_info import Operator` |
| 4 | `import numpy as np` | - | IK | numpy | - |
| 5 | `from scipy.linalg import expm` | - | IK | scipy.linalg | - |
| 6 | `pauli_z = Pauli('Z').to_matrix()` | Deprecation -> to_matrix() method is deprecated | qrn_notax_ddbb-4f99b3f4-5a45-4606-9c64-99023d96f577 | Pauli | `pauli_z = Pauli('Z').to_operator()` |
| 7 | `pauli_x = Pauli('X').to_matrix()` | Deprecation -> to_matrix() method is deprecated | qrn_notax_ddbb-4f99b3f4-5a45-4606-9c64-99023d96f577 | Pauli | `pauli_x = Pauli('X').to_operator()` |
| 8 | `hamiltonian = 0.5 * pauli_z + 0.3 * pauli_x` | - | IK | hamiltonian | - |
| 9 | `time = 1.0` | - | IK | time | - |
| 10 | `evolution_matrix = expm(-1j * hamiltonian * time)` | - | IK | evolution_matrix | - |
| 11 | `U, s, Vh = np.linalg.svd(evolution_matrix)` | - | IK | np.linalg.svd | - |
| 12 | `evolution_matrix = U @ Vh` | - | IK | evolution_matrix | - |
| 13 | `qc = QuantumCircuit(1)` | - | IK | QuantumCircuit | - |
| 14 | `qc.h(0)` | - | IK | qc | - |
| 15 | `qc.unitary(Operator(evolution_matrix), [0])` | Updated -> usage of Operator() has changed | qrn_notax_ddbb-f84bdfe5-5249-4875-b0c2-897541351b96 | qc | `qc.unitary(evolution_matrix, [0])` |
| 16 | `simulator = Aer.get_backend('statevector_simulator')` | Updated -> Aer.get_backend() method is deprecated | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | Aer | `simulator = BasicProvider().get_backend('statevector_simulator')` |
| 17 | `result = execute(qc, simulator).result()` | Deprecation -> execute() function is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `result = backend.run(qc)` |
| 18 | `statevector = result.get_statevector()` | - | IK | result | - |
| 19 | `target_state = np.array([0, 1])` | - | IK | target_state | - |
| 20 | `fidelity = state_fidelity(statevector, target_state)` | Updated -> state_fidelity has been updated to reflect changes | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | state_fidelity | - |
| 21 | `print(f"Fidelity: {fidelity:.4f}")` | - | IK | print | - |

```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.quantum_info import Statevector, Pauli
import numpy as np
from scipy.linalg import expm

pauli_z = Pauli('Z').to_operator()
pauli_x = Pauli('X').to_operator()
hamiltonian = 0.5 * pauli_z + 0.3 * pauli_x

time = 1.0
evolution_matrix = expm(-1j * hamiltonian * time)
U, s, Vh = np.linalg.svd(evolution_matrix)
evolution_matrix = U @ Vh
qc = QuantumCircuit(1)
qc.h(0)
qc.unitary(evolution_matrix, [0])

simulator = BasicProvider().get_backend('statevector_simulator')
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```