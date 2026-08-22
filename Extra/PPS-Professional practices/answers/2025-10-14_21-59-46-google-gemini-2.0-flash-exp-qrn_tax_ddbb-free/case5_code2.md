| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by Estimator, Sampler, or algorithm classes which are part of the qiskit.primitives name space. | qrn_tax_ddbb-d9872a822bb24849a06535b1c73a6b48 | execute | `from qiskit import QuantumCircuit, Aer` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> Class `quantum_info.operators.Operator` deprecated | qrn_tax_ddbb-24a795142a514e9aa59e185128793278 | qiskit.quantum_info.operators.Operator | `from qiskit.quantum_info import Pauli, state_fidelity, Operator` |
| 3 | `from qiskit.quantum_info.operators import Operator` | Moved -> The object `qiskit.quantum_info.operators.Operator` has been moved to `qiskit.quantum_info.Operator`. | qrn_tax_ddbb-0c3b0e93946348a4a49249e4e931455d | qiskit.quantum_info.operators.Operator |  |
| 17 | `simulator = Aer.get_backend('statevector_simulator')` | Changed -> The return type of `backend.run` method now returns a BaseJob subclass instance | qrn_tax_ddbb-658bc46736884931b7695449c09e01b2 | Aer.get_backend | `simulator = Aer.get_backend('statevector_simulator')` |
| 18 | `result = execute(qc, simulator).result()` | Deprecation -> The `execute` function is deprecated and will be removed in a future release. It is replaced by Estimator, Sampler, or algorithm classes which are part of the qiskit.primitives name space. | qrn_tax_ddbb-d9872a822bb24849a06535b1c73a6b48 | execute | `from qiskit.primitives import Sampler, Estimator` <br>`sampler = Sampler(options={"shots": 100})`<br>`job = sampler.run(qc)`<br>`result = job.result()`<br>`statevector = result.quasi_dists[0]` |
| 19 | `statevector = result.get_statevector()` | Removed -> `qiskit.Result` no longer has a `get_statevector()` method | qrn_tax_ddbb-33990 | result.get_statevector | `statevector = result.quasi_dists[0]` |

```python
from qiskit import QuantumCircuit, Aer
from qiskit.quantum_info import Pauli, state_fidelity, Operator
import numpy as np
from scipy.linalg import expm
from qiskit.primitives import Sampler, Estimator

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
sampler = Sampler(options={"shots": 100})
job = sampler.run(qc)
result = job.result()
statevector = result.quasi_dists[0]

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```