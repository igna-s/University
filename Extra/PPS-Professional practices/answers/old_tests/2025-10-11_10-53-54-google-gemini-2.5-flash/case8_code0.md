| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> qiskit.Aer object deprecated | * | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `QuantumInstance` class deprecated and removed. Functionality integrated into primitives. | * | internal | qiskit.utils.QuantumInstance | |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `algorithm_globals` module deprecated. | * | internal | qiskit.utils.algorithm_globals | |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> `qiskit.opflow` module deprecated. Use `qiskit.quantum_info.SparsePauliOp` or `qiskit.quantum_info.Pauli` instead. | * | internal | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> `Opflow` operators (`^` for tensor product, `+` for sum) deprecated. Use `SparsePauliOp` for Hamiltonian construction. | * | internal | (Z ^ I) + (X ^ X) | `hamiltonian = SparsePauliOp.from_list([("ZI", 1), ("XX", 1)])` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> `algorithm_globals.random` deprecated. Use `numpy.random` instead. | * | internal | algorithm_globals.random.random | `initial_point = np.random.rand(ansatz.num_parameters)` |
| 13 | `quantum_instance = QuantumInstance(` | Deprecation -> `QuantumInstance` class deprecated and removed. | * | internal | QuantumInstance | |


```python
import numpy as np
from qiskit_aer import Aer
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import SparsePauliOp

hamiltonian = SparsePauliOp.from_list([("ZI", 1), ("XX", 1)])
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.rand(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
```