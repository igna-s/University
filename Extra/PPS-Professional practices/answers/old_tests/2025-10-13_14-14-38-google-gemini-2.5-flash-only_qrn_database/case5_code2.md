| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module deprecated | * | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer | `from qiskit.providers.basic_provider import BasicSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute()` function deprecated | * | 8878ac1a-c067-4924-a116-185016f37a9c | execute | |
| 20 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend` method for `statevector_simulator` is deprecated. | * | c7fe0ecc-6b73-4aed-a0c6-25de630eb29d | Aer.get_backend | `simulator = BasicSimulator()` |
| 21 | `result = execute(qc, simulator).result()` | Deprecation -> `execute()` function deprecated | * | 8878ac1a-c067-4924-a116-185016f37a9c | execute | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, state_fidelity
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm
from qiskit.providers.basic_provider import BasicSimulator

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

simulator = BasicSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```