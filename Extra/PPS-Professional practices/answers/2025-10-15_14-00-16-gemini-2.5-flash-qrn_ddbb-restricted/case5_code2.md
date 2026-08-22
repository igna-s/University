| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer.get_backend()` is deprecated. `qiskit.execute()` is deprecated. | qrn_notax_ddbb-f5255018-c2a7-4766-993d-8153406f86b4 | qiskit.Aer | `from qiskit.transpiler import PassManager` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> `state_fidelity` has been deprecated. | qrn_notax_ddbb-ea396e62-4efc-4074-be46-24e5ef905ddc | state_fidelity | `from qiskit.quantum_info.states import partial_trace` |
| 18 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | qrn_notax_ddbb-f5255018-c2a7-4766-993d-8153406f86b4 | Aer.get_backend | `from qiskit.providers.basic_provider import BasicSimulator` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> `qiskit.execute()` is deprecated. | qrn_notax_ddbb-f5255018-c2a7-4766-993d-8153406f86b4 | execute | `result = BasicSimulator().run(qc).result()` |
| 23 | `fidelity = state_fidelity(statevector, target_state)` | Deprecation -> `state_fidelity` has been deprecated. | qrn_notax_ddbb-ea396e62-4efc-4074-be46-24e5ef905ddc | state_fidelity | `from qiskit.quantum_info.states import Statevector` |

```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli
from qiskit.quantum_info.operators import Operator
from qiskit.providers.basic_provider import BasicSimulator
from qiskit.quantum_info.states import Statevector
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

simulator = BasicSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = Statevector(np.array([0, 1]))
fidelity = statevector.inner(target_state)
print(f"Fidelity: {fidelity:.4f}")
```