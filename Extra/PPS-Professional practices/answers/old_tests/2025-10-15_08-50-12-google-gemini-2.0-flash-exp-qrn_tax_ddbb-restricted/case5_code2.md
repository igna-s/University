| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by the `Sampler` and `Estimator` classes. | qrn_tax_ddbb-6244cd96-36cf-4514-b391-31b989c63c73 | execute | `from qiskit.providers import backend_v2 as backend` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Moved to qiskit.providers | qrn_tax_ddbb-1499489c-2e89-45a2-b244-093893b81331 | Aer | `from qiskit.providers.aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Moved to qiskit.quantum_info | qrn_tax_ddbb-f4f96352-6166-4932-b853-149b11b1a357 | QuantumCircuit | `from qiskit.quantum_info import Statevector` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by the `Sampler` and `Estimator` classes. | qrn_tax_ddbb-1499489c-2e89-45a2-b244-093893b81331 | execute | `from qiskit.primitives import Sampler` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Moved to qiskit.quantum_info | IK | state_fidelity | `from qiskit.quantum_info import  state_fidelity` |
| 18 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | qrn_tax_ddbb-2c76159f-b595-4512-9504-4075c3f3dd5d | Aer.get_backend | `simulator = AerSimulator()` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by the `Sampler` and `Estimator` classes. | qrn_tax_ddbb-6244cd96-36cf-4514-b391-31b989c63c73 | execute | `sampler = Sampler(options={"shots": 100})` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by the `Sampler` and `Estimator` classes. | qrn_tax_ddbb-6244cd96-36cf-4514-b391-31b989c63c73 | execute | `job = sampler.run(qc)` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by the `Sampler` and `Estimator` classes. | qrn_tax_ddbb-6244cd96-36cf-4514-b391-31b989c63c73 | execute | `result = job.result()` |
| 20 | `statevector = result.get_statevector()` | Deprecation -> Return a dict of counts. get_statevector will be removed | qrn_tax_ddbb-3a8ca894-992b-451f-89aa-f709a8d4a595 | get_statevector | `statevector = Statevector.from_int(result.quasi_dists[0].most_frequent(), dims=(2,)).data` |

```python
from qiskit import QuantumCircuit
from qiskit.providers.aer import AerSimulator
from qiskit.quantum_info import Pauli, state_fidelity, Statevector
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm
from qiskit.primitives import Sampler

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
sampler = Sampler(options={"shots": 100})
job = sampler.run(qc)
result = job.result()
statevector = Statevector.from_int(result.quasi_dists[0].most_frequent(), dims=(2,)).data

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```