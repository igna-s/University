| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 5 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The Aer module has been deprecated and will be removed in Qiskit 1.0. Use qiskit_aer instead. | qrn_tax_ddbb-4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit | `from qiskit import QuantumCircuit, qiskit_aer as Aer, execute` |
| 7 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Use qiskit_aer instead of Aer | qrn_tax_ddbb-4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit | `simulator = qiskit_aer.get_backend('statevector_simulator')` | 

```python
from qiskit import QuantumCircuit, qiskit_aer as Aer, execute
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
qc.unitary(Operator(evolution_matrix), [0])

simulator = qiskit_aer.get_backend('statevector_simulator')
result = execute(qc, simulator).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```