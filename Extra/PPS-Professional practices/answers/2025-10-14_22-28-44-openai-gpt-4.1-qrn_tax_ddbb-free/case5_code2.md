| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> execute() function is deprecated | qrn_tax_ddbb-1b144bc1602d4b49bc8a6a829a850d43 | qiskit.execute | Use Qiskit primitives or backend.run instead. For simulation, use AerSimulator and transpile + backend.run workflow. |
| 13 | `simulator = Aer.get_backend('statevector_simulator')` | Deprecation -> Aer.get_backend has been replaced by AerSimulator | qrn_tax_ddbb-bbc1b2bc001d45e3809313c292c84a1b | qiskit.Aer.get_backend | Use AerSimulator instead: `from qiskit_aer import AerSimulator` and instantiate `AerSimulator()` |
| 14 | `result = execute(qc, simulator).result()` | Deprecation -> execute() function is deprecated | qrn_tax_ddbb-1b144bc1602d4b49bc8a6a829a850d43 | qiskit.execute | Use backend.run(transpile(...)) workflow: `from qiskit import transpile; tqc = transpile(qc, simulator); result = simulator.run(tqc).result()` |
| 15 | `statevector = result.get_statevector()` | API Change -> use result.data() for statevector in AerSimulator | qrn_tax_ddbb-2bf3de2c31424716bae24a998c4e3c25 | qiskit.result.get_statevector | Use: `statevector = result.data()['statevector']` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.quantum_info import Pauli, state_fidelity
from qiskit.quantum_info.operators import Operator
import numpy as np
from scipy.linalg import expm
from qiskit_aer import AerSimulator

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
tqc = transpile(qc, simulator)
result = simulator.run(tqc).result()
statevector = result.data()['statevector']

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```