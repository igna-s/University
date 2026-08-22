| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import QuantumCircuit, Aer, execute | Deprecation -> execute() is deprecated and Aer moved to qiskit_aer | qrn_tax_ddbb--571e9e95-366f-4fab-aa26-31fa91b3dca5 | execute, Aer | from qiskit import QuantumCircuit; from qiskit_aer import Aer |
| 2 | from qiskit.quantum_info import Pauli, state_fidelity | Import Adjustments -> Pauli import location changed | qrn_tax_ddbb--7b635ad2-a23d-43d2-b661-741c0d1fde3c | Pauli | from qiskit.quantum_info.operators import Pauli |
| 11 | simulator = Aer.get_backend('statevector_simulator') | Updated Backend Access -> get_backend usage updated | qrn_tax_ddbb--9c55b443-3453-46e7-95a4-fc8fdc3601e2 | get_backend | simulator = Aer.statevector_simulator() |
| 12 | result = execute(qc, simulator).result() | Deprecation -> execute() function is deprecated | qrn_tax_ddbb--571e9e95-366f-4fab-aa26-31fa91b3dca5 | execute | result = simulator.run(qc).result() |

```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.quantum_info.operators import Pauli, Operator
from qiskit.quantum_info import state_fidelity
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

simulator = Aer.statevector_simulator()
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```