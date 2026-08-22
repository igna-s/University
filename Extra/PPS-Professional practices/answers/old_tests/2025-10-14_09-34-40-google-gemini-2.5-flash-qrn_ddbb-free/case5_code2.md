| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `Aer` module is deprecated. | qrn_ddbb-589d | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function is deprecated. | qrn_ddbb-b054 | execute | `(remove import)` |
| 23 | `fidelity = state_fidelity(statevector, target_state)` | Deprecation -> The `state_fidelity` function is deprecated. | qrn_ddbb-c324 | state_fidelity | `fidelity = StateFidelity().evaluate(statevector, target_state)` |
| 18 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | qrn_ddbb-589d | Aer.get_backend | `simulator = AerSimulator()` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute()` function is deprecated. | qrn_ddbb-b054 | execute | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli, Operator, StateFidelity
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
fidelity = StateFidelity().evaluate(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```