| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | * | f9660e82-508c-4d89-81e3-c97a551ef265 | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function is deprecated. | * | Internal Knowledge | execute | |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | * | d724fd08-0363-4e67-9eb3-6fad8e2b8a61 | Aer.get_backend | `simulator = AerSimulator()` |
| 20 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated. | * | Internal Knowledge | execute | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli, state_fidelity
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

simulator = AerSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```