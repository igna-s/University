| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `Aer` | Deprecation -> Deprecation of qiskit.Aer object | * | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 1 | `execute` | Deprecation -> Deprecation of execute() function | * | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute() | (removed) |
| 19 | `execute(qc, simulator)` | Deprecation -> Deprecation of execute() function | * | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | execute() | `transpile(qc, simulator).run()` |


```python
from qiskit import QuantumCircuit
from qiskit.quantum_info import Pauli, state_fidelity
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm
from qiskit_aer import Aer
from qiskit import transpile

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
transpiled_qc = transpile(qc, simulator)
result = simulator.run(transpiled_qc).result()

statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```