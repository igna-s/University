| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import QuantumCircuit, Aer, execute | Deprecation -> execute() is deprecated; Aer legacy import is deprecated | qrn_ddbb-5adeceed08c75c993884f8f1de943d27 | execute, Aer | from qiskit import QuantumCircuit; from qiskit_aer import Aer; from qiskit.primitives import BackendSampler |
| 13 | simulator = Aer.get_backend('statevector_simulator') | Deprecation -> Aer.get_backend() moved to qiskit_aer | qrn_ddbb-22e6e1c84ae94936b38ea4bb1a99b2b1 | Aer.get_backend | simulator = Aer.get_backend('statevector_simulator') |
| 14 | result = execute(qc, simulator).result() | Deprecation -> execute() is deprecated | qrn_ddbb-fae587a9eabbdbc950c8073cdcb71d43 | execute | sampler = BackendSampler(simulator); job = sampler.run(qc); result = job.result(); statevector = result.get_value().flatten() |
| 15 | statevector = result.get_statevector() | Deprecation -> result.get_statevector() replaced by result.get_value() | qrn_ddbb-127d229ea06b4fc28e84297b8ae88c57 | result.get_statevector |  |

```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, state_fidelity
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm
from qiskit_aer import Aer
from qiskit.primitives import BackendSampler

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

simulator = Aer.get_backend('statevector_simulator')
sampler = BackendSampler(simulator)
job = sampler.run(qc)
result = job.result()
statevector = result.get_value().flatten()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```