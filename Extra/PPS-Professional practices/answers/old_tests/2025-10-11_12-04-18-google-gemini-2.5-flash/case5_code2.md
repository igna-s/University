| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of execute() function | bc39cc74-3382-4b55-bc9c-c44558547f03 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute | |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> The `qiskit.quantum_info.operators` module is deprecated. | * | internal | qiskit.quantum_info.operators | `from qiskit.quantum_info import Pauli, state_fidelity, Operator` |
| 3 | `from qiskit.quantum_info.operators import Operator` | Deprecation -> The `qiskit.quantum_info.operators` module is deprecated. | * | internal | qiskit.quantum_info.operators | |
| 20 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | Aer.get_backend | `simulator = AerSimulator()` |
| 21 | `result = execute(qc, simulator).result()` | Deprecation -> Deprecation of execute() function | bc39cc74-3382-4b55-bc9c-c44558547f03 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute | `result = simulator.run(qc).result()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
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
qc.unitary(Operator(evolution_matrix), [0])

simulator = AerSimulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```