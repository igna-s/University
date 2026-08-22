| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing Aer and execute from qiskit is deprecated. Use AerSimulator from qiskit.providers.aer and backend.run instead. | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | Aer, execute | `from qiskit import QuantumCircuit`<br>`from qiskit.providers.aer import AerSimulator` |
| 18 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Aer.get_backend('statevector_simulator') is deprecated. Use AerSimulator() or AerSimulator(method="statevector"). | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | Aer.get_backend | `simulator = AerSimulator()` |
| 19 | `result = execute(qc, simulator).result()` | Deprecation -> execute() is deprecated. Use backend.run(circuit).result(). | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | execute | `result = simulator.run(qc).result()` |

**Refactored Python code for Qiskit 1.0.0**

```python
from qiskit import QuantumCircuit
from qiskit.providers.aer import AerSimulator
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

simulator = AerSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```