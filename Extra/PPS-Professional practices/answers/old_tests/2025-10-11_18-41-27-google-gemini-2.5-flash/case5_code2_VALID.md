| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` is deprecated and moved to `qiskit_aer` | * | internal | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` import no longer needed (use backend.run) | * | internal | execute | Remove from import; use `simulator.run(qc).result()` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> `state_fidelity` moved to `qiskit.quantum_info.fidelity` | * | internal | state_fidelity | `from qiskit.quantum_info.fidelity import state_fidelity` |
| 16 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend` removed; use `AerSimulator` | * | internal | Aer.get_backend | `simulator = AerSimulator(method='statevector')` |
| 17 | `result = execute(qc, simulator).result()` | Deprecation -> `execute` not required; use `backend.run` | * | internal | execute | `result = simulator.run(qc).result()` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli
from qiskit.quantum_info.fidelity import state_fidelity
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

simulator = AerSimulator(method='statevector')
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```
