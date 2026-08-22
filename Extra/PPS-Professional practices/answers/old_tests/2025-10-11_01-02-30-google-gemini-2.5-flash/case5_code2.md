| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `qiskit.execute()` function is deprecated. | 39f886f3-f590-482f-8700-11100f91a979 | qiskit.execute | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `qiskit.Aer` module has been moved to `qiskit_aer`. | ee4d9c49-d3e7-49f2-8ce1-b27b3e098dfa | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 17 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> The `Aer.get_backend()` method is deprecated. | ee4d9c49-d3e7-49f2-8ce1-b27b3e098dfa | Aer.get_backend | `simulator = AerSimulator()` |
| 18 | `result = execute(qc, simulator).result()` | Deprecation -> The `qiskit.execute()` function is deprecated. | 39f886f3-f590-482f-8700-11100f91a979 | execute | `result = simulator.run(qc).result()` |
| 21 | `fidelity = state_fidelity(statevector, target_state)` | Deprecation -> The `qiskit.quantum_info.state_fidelity()` function is deprecated. | 3a42fe83-e028-4e3a-96ad-5a415a2ec35f | qiskit.quantum_info.state_fidelity | `fidelity = Statevector.from_int(0,2).to_density_matrix().fidelity(Statevector(target_state))` |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, Operator, Statevector
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
fidelity = Statevector(statevector).fidelity(Statevector(target_state))
print(f"Fidelity: {fidelity:.4f}")
```