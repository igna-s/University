| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Importing from `qiskit.providers.aer` is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `QuantumInstance` class is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | QuantumInstance | `from qiskit.primitives import Sampler` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `algorithm_globals` is deprecated | IK | algorithm_globals |  |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> `qiskit.opflow` module is deprecated | IK | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> `qiskit.opflow` operators are deprecated | IK | Z, I, X, ^, + | `hamiltonian = SparsePauliOp.from_list([("ZI", 1), ("XX", 1)])` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> `algorithm_globals.random` is deprecated | IK | algorithm_globals.random | `initial_point = np.random.default_rng(seed=RANDOM_SEED).random(ansatz.num_parameters)` |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend | `backend = AerSimulator(shots=1024, seed_simulator=RANDOM_SEED)` |
| 13 | `quantum_instance = QuantumInstance(` | Deprecation -> `QuantumInstance` class is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | QuantumInstance | (Removed) |
| 16 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> `algorithm_globals.random_seed` is deprecated | IK | algorithm_globals.random_seed | `seed_simulator=RANDOM_SEED` |
| 17 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> `algorithm_globals.random_seed` is deprecated | IK | algorithm_globals.random_seed | (Removed, handled by explicit transpilation or primitive options) |


```python
import numpy as np
from qiskit_aer import AerSimulator
from qiskit.primitives import Sampler
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import SparsePauliOp

RANDOM_SEED = 42

hamiltonian = SparsePauliOp.from_list([("ZI", 1), ("XX", 1)])
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.default_rng(seed=RANDOM_SEED).random(ansatz.num_parameters)

backend = AerSimulator(shots=1024, seed_simulator=RANDOM_SEED)
sampler = Sampler(backend=backend)
```