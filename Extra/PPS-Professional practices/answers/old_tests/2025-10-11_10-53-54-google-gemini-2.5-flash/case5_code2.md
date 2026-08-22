| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | `Aer` | Remove `Aer` from import statement. Use `qiskit.quantum_info.Statevector` for statevector simulation. |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of execute() function | bc39cc74-3382-4b55-bc9c-c44558547f03 | bc39cc74-3382-4b55-bc9c-c44558547f03 | `execute` | Remove `execute` from import statement. Replace `execute(qc, simulator).result()` with `Statevector(qc)`. |
| 2 | `from qiskit.quantum_info import Pauli, state_fidelity` | Deprecation -> The `state_fidelity()` function has moved to `qiskit.quantum_info.fidelity` | * | internal | `state_fidelity` | `from qiskit.quantum_info.fidelity import state_fidelity` |
| 20 | `simulator = Aer.get_backend('statevector_simulator')` | Structural change -> Migration: Statevector simulator. Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | `Aer.get_backend('statevector_simulator')` | Replaced by direct `Statevector(qc)` initialization. |
| 21 | `result = execute(qc, simulator).result()` | Deprecation -> Deprecation of execute() function | bc39cc74-3382-4b55-bc9c-c44558547f03 | bc39cc74-3382-4b55-bc9c-c44558547f03 | `execute()` | Replaced by direct `statevector = Statevector(qc)` initialization. |
| 22 | `statevector = result.get_statevector()` | Structural change -> Migration: Statevector simulator. Use `Statevector` from `qiskit.quantum_info` instead of BasicAer | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | 514aa795-3e1d-4687-bdf6-647cb9fe1773 | `result.get_statevector()` | Statevector is directly `Statevector(qc)`. |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, Operator, Statevector
from qiskit.quantum_info.fidelity import state_fidelity
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

statevector = Statevector(qc)

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```