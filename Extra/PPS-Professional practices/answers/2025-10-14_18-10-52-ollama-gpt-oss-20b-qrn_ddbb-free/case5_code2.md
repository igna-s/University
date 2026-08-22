| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :--------: | :------- | :---------- |  
| 1 | from qiskit import QuantumCircuit, Aer, execute | Deprecation -> execute() function removed in 1.0.0 | IK | execute | from qiskit import QuantumCircuit, Aer |  
| 17 | qc.unitary(Operator(evolution_matrix), [0]) | Deprecation -> unitary() method removed in 1.0.0 | IK | unitary | qc.append(Operator(evolution_matrix), [0]) |  
| 20 | result = execute(qc, simulator).result() | Deprecation -> execute() function removed in 1.0.0 | IK | execute | result = simulator.run(qc).result() |  

```python  
from qiskit import QuantumCircuit, Aer
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
qc.append(Operator(evolution_matrix), [0])

simulator = Aer.get_backend('statevector_simulator')
result = simulator.run(qc).result()
statevector = result.get_statevector()

target_state = np.array([0, 1])
fidelity = state_fidelity(statevector, target_state)
print(f"Fidelity: {fidelity:.4f}")
```