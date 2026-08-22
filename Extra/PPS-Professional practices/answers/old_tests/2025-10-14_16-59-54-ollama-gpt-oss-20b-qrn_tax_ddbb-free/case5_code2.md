| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Import Aer provider from qiskit.providers.aer | IK | Aer | `from qiskit import QuantumCircuit, execute; from qiskit.providers.aer import AerSimulator` |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> Import state_fidelity from qiskit.quantum_info.states.utils | IK | state_fidelity | `from qiskit.quantum_info import Pauli; from qiskit.quantum_info.states.utils import state_fidelity` |
| 3 | `from qiskit.quantum_info.operators import Operator` | Deprecation -> Import UnitaryGate from qiskit.circuit.library | IK | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 17 | `qc.unitary(Operator(evolution_matrix), [0])` | Deprecation -> Replace qc.unitary(Operator) with qc.append(UnitaryGate) | IK | qc.unitary | `qc.append(UnitaryGate(evolution_matrix), [0])` |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Replace Aer.get_backend('statevector_simulator') with AerSimulator(method='statevector') | IK | Aer.get_backend | `simulator = AerSimulator(method='statevector')` |

```python
from qiskit import QuantumCircuit, execute; from qiskit.providers.aer import AerSimulator
from qiskit.quantum_info import Pauli; from qiskit.quantum_info.states.utils import state_fidelity
from qiskit.circuit.library import UnitaryGate
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
qc.append(UnitaryGate(evolution_matrix), [0])

simulator = AerSimulator(method='statevector')
result = execute(qc, simulator).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```