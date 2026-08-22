| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 1 | `import execute` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> The state_fidelity() function has moved | IK | state_fidelity | `from qiskit.quantum_info.states import state_fidelity` |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Aer.get_backend() is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend() | `simulator = AerSimulator()` |
| 20 | `result = execute(qc, simulator).result()` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli
from qiskit.quantum_info.operators import Operator
from qiskit.quantum_info.states import state_fidelity
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