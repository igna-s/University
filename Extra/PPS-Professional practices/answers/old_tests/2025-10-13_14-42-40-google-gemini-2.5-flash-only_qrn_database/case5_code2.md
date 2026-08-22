| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. | 65 | ce25a304-5b28-43b2-8a0d-9b31e0b13fb7 | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Qiskit’s execute() function is deprecated. | * | 8878ac1a-c067-4924-a116-185016f37a9c | execute | |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | 68 | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer.get_backend | `simulator = AerSimulator()` |
| 20 | `result = execute(qc, simulator).result()` | Deprecation -> Qiskit’s execute() function is deprecated. | * | 8878ac1a-c067-4924-a116-185016f37a9c | execute | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, state_fidelity
from qiskit.quantum_info.operators import Operator
from qiskit_aer import AerSimulator
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

simulator = AerSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```