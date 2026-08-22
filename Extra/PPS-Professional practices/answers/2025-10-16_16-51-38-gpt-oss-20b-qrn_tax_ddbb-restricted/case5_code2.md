| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | Aer | `from qiskit_aer import AerSimulator` |
| 17 | `qc.unitary(Operator(evolution_matrix), [0])` | Deprecation -> QuantumCircuit.unitary method is deprecated and should use UnitaryGate. | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | QuantumCircuit.unitary | `qc.append(Operator(evolution_matrix).to_instruction(), [0])` |
| 19 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend | `simulator = AerSimulator('statevector_simulator')` |

```python
from qiskit import QuantumCircuit, execute
from qiskit_aer import AerSimulator
from qiskit.quantum_info import Pauli, state_fidelity
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
qc.append(Operator(evolution_matrix).to_instruction(), [0])

simulator = AerSimulator('statevector_simulator')
result = execute(qc, simulator).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```