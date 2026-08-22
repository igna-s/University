| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import QuantumCircuit, Aer, execute | Deprecation -> Aer and execute modules deprecated | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer/execute |  |
| 13 | simulator = Aer.get_backend('statevector_simulator') | Deprecated method -> Aer.get_backend deprecated, use Statevector(qc) instead | qrn_notax_ddbb--a4289ec8-8488-4fa4-99f8-c46141a06471 | Aer.get_backend |  |
| 14 | result = execute(qc, simulator).result() | Deprecated method -> execute() deprecated, use Statevector(qc) directly | qrn_notax_ddbb--9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | execute |  |
| 15 | statevector = result.get_statevector() | Deprecated usage -> use Statevector(qc) instead of .result().get_statevector() | qrn_notax_ddbb--9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | .get_statevector | statevector = Statevector(qc) |

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