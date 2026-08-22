| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing from qiskit.providers.aer is deprecated | IK | qiskit.providers.aer | `from qiskit import QuantumCircuit, Aer as qiskit_aer, execute` |  
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` |  |  |  |  |  
| 3 | `from qiskit.quantum_info.operators import Operator` |  |  |  |  |  
| 4 | `import numpy as np` |  |  |  |  |  
| 5 | `from scipy.linalg import expm` |  |  |  |  |  
| 7 | `h = 0.5 * pauli_z + 0.3 * pauli_x` |  |  |  |  |  
| 9 | `evolution_matrix = expm(-1j * h * time)` |  |  |  |  |  
| 10 | `U, s, Vh = np.linalg.svd(evolution_matrix)` |  |  |  |  |  
| 11 | `evolution_matrix = U @ Vh` |  |  |  |  |  
| 12 | `qc = QuantumCircuit(1)` |  |  |  |  |  
| 13 | `qc.h(0)` |  |  |  |  |  
| 14 | `qc.unitary(Operator(evolution_matrix), [0])` |  |  |  |  |  
| 16 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Getting backend from Aer is deprecated | IK | qiskit.providers.aer | `simulator = qiskit_aer.get_backend('statevector_simulator')` |  
| 17 | `result = execute(qc, simulator).result()` |  |  |  |  |  
| 18 | `statevector = result.get_statevector()` |  |  |  |  |  
| 20 | `fidelity = state_fidelity(statevector, target_state)` |  |  |  |  |  
| 21 | `print(f"Fidelity: {fidelity:.4f}")` |  |  |  |  |  

```python
from qiskit import QuantumCircuit, Aer as qiskit_aer, execute
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