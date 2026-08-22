| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module and `execute` function are deprecated | Internal Knowledge | Aer, execute | `from qiskit import QuantumCircuit` <br> `from qiskit_aer import AerSimulator` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> `state_fidelity` function is deprecated | Internal Knowledge | state_fidelity | `from qiskit.quantum_info import Pauli, Statevector` |
| 17 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend` is deprecated in favor of direct simulator instantiation | Internal Knowledge | Aer.get_backend | `simulator = AerSimulator()` |
| 18 | `result = execute(qc, simulator).result()` | Deprecation -> `execute` function is deprecated, use `simulator.run()` instead | Internal Knowledge | execute | `result = simulator.run(qc).result()` |
| 22 | `fidelity = state_fidelity(statevector, target_state)` | Deprecation -> `state_fidelity` function is deprecated, use `Statevector.fidelity()` method | Internal Knowledge | state_fidelity | `fidelity = Statevector(statevector).fidelity(target_state)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli, Statevector
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
fidelity = Statevector(statevector).fidelity(target_state)
print(f"Fidelity: {fidelity:.4f}")
```