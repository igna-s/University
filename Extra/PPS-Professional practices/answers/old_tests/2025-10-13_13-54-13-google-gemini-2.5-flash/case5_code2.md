| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Import of execute from qiskit is deprecated; import from qiskit.execute instead | * | Internal Knowledge | execute | `from qiskit import QuantumCircuit, Aer`<br>`from qiskit.execute import execute` |
| 3 | `from qiskit.quantum_info.operators import Operator` | Deprecation -> Operator import path changed to qiskit.quantum_info | * | Internal Knowledge | Operator | `from qiskit.quantum_info import Operator` |
| 17 | `qc.unitary(Operator(evolution_matrix), [0])` | Deprecation -> QuantumCircuit.unitary is removed; use append with instruction | * | Internal Knowledge | QuantumCircuit.unitary | `qc.append(Operator(evolution_matrix).to_instruction(), [0])` |

```python
from qiskit import QuantumCircuit, Aer
from qiskit.execute import execute
from qiskit.quantum_info import Pauli, state_fidelity, Operator
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
qc.append(Operator(evolution_matrix).to_instruction(), [0])

simulator = Aer.get_backend('statevector_simulator')
result = execute(qc, simulator).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```
