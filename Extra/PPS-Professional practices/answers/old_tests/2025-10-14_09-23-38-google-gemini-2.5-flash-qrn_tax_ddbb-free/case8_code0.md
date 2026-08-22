| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `QuantumInstance` has been deprecated. | Internal Knowledge | `QuantumInstance` | |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `algorithm_globals` has been deprecated. | Internal Knowledge | `algorithm_globals` | `from qiskit.utils import algorithm_globals as _algorithm_globals` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> The entire `qiskit.opflow` module has been deprecated. | Internal Knowledge | `qiskit.opflow` | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> `qiskit.opflow` operators are deprecated. | Internal Knowledge | `Z`, `I`, `X` | `hamiltonian = SparsePauliOp(['ZI', 'XX'], coeffs=[1, 1])` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> `algorithm_globals` has been deprecated. | Internal Knowledge | `algorithm_globals.random.random` | `initial_point = np.random.rand(ansatz.num_parameters)` |
| 12 | `quantum_instance = QuantumInstance(` | Deprecation -> `QuantumInstance` has been deprecated. | Internal Knowledge | `QuantumInstance` | |
| 15 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> `algorithm_globals` has been deprecated. | Internal Knowledge | `algorithm_globals.random_seed` | `seed_simulator=np.random.randint(1000)` |
| 16 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> `algorithm_globals` has been deprecated. | Internal Knowledge | `algorithm_globals.random_seed` | `seed_transpiler=np.random.randint(1000)` |


```python
from qiskit import Aer
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = SparsePauliOp(['ZI', 'XX'], coeffs=[1, 1])
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.rand(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
```