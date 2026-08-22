| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Use of the qiskit.Aer object is deprecated. | * | ce25a304-5b28-43b2-8a0d-9b31e0b13fb7 | qiskit.Aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The qiskit.utils.QuantumInstance class is deprecated. | * | Internal Knowledge | QuantumInstance | |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend() is deprecated. | * | Internal Knowledge | Aer.get_backend | `backend = AerSimulator()` |
| 13 | `quantum_instance = QuantumInstance(` | Deprecation -> The qiskit.utils.QuantumInstance class is deprecated. | * | Internal Knowledge | QuantumInstance | |


```python
from qiskit_aer import AerSimulator
from qiskit.circuit.library import TwoLocal
from qiskit.opflow import Z, I, X
import numpy as np
from qiskit.utils import algorithm_globals

hamiltonian = (Z ^ I) + (X ^ X)
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = algorithm_globals.random.random(ansatz.num_parameters)

backend = AerSimulator()
```