| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Meta-package -> Aer is deprecated and distributed in qiskit-aer | qrn_ddbb-e46b9eb237182019a97efc40b06879c7 | Aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The class `QuantumInstance` is deprecated and will be removed no earlier than 3 months after the release date. It was replaced by `Sampler` and `Estimator` primitives. | qrn_ddbb-a942684b9558434d94ca493340f34601 | QuantumInstance |  |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `algorithm_globals` is deprecated and will be removed in a future release. For random generators relying on the `algorithm_globals.random_seed` the user should use a `numpy.random.Generator` directly. | qrn_ddbb-21399906c0b48337871394a956ffc79a | algorithm_globals |  |
| 3 | `from qiskit.circuit.library import TwoLocal` | Package change -> Moved to qiskit.circuit.library. | IK | qiskit.circuit.library | `from qiskit.circuit.library.n_local import TwoLocal` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> Module `qiskit.opflow` is deprecated and replaced with `qiskit.quantum_info` | qrn_ddbb-c99367b04c911a445a7624859c946d3a | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 4 | `from qiskit.opflow import Z, I, X` | Replacement -> `Z` is replaced by `SparsePauliOp.from_list([("Z", 1)])` | IK | Z |  |
| 4 | `from qiskit.opflow import Z, I, X` | Replacement -> `I` is replaced by `SparsePauliOp.from_list([("I", 1)])` | IK | I |  |
| 4 | `from qiskit.opflow import Z, I, X` | Replacement -> `X` is replaced by `SparsePauliOp.from_list([("X", 1)])` | IK | X |  |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Change in behavior -> The `^` operator was changed to `^` | IK |  | `hamiltonian = (Z @ I) + (X @ X)` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> `algorithm_globals` is deprecated and will be removed in a future release. For random generators relying on the `algorithm_globals.random_seed` the user should use a `numpy.random.Generator` directly. | qrn_ddbb-21399906c0b48337871394a956ffc79a | algorithm_globals | `rng = np.random.default_rng(algorithm_globals.random_seed)`<br>`initial_point = rng.random(ansatz.num_parameters)` |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Function replacement -> Use `QiskitAer.get_backend('name')` instead of `Aer.get_backend('name')` | IK | Aer.get_backend | `backend = Aer.get_backend('aer_simulator')` |
| 13 | `quantum_instance = QuantumInstance(` | Deprecation -> The class `QuantumInstance` is deprecated and will be removed no earlier than 3 months after the release date. It was replaced by `Sampler` and `Estimator` primitives. | qrn_ddbb-a942684b9558434d94ca493340f34601 | QuantumInstance |  |
| 15 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> `algorithm_globals` is deprecated and will be removed in a future release. For random generators relying on the `algorithm_globals.random_seed` the user should use a `numpy.random.Generator` directly. | qrn_ddbb-21399906c0b48337871394a956ffc79a | algorithm_globals | `seed_simulator=algorithm_globals.random_seed,` |
| 16 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> `algorithm_globals` is deprecated and will be removed in a future release. For random generators relying on the `algorithm_globals.random_seed` the user should use a `numpy.random.Generator` directly. | qrn_ddbb-21399906c0b48337871394a956ffc79a | algorithm_globals | `seed_transpiler=algorithm_globals.random_seed` |

```python
from qiskit_aer import Aer
from qiskit.circuit.library.n_local import TwoLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = (SparsePauliOp.from_list([("Z", 1)]) @ SparsePauliOp.from_list([("I", 1)])) + (SparsePauliOp.from_list([("X", 1)]) @ SparsePauliOp.from_list([("X", 1)]))
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
rng = np.random.default_rng(algorithm_globals.random_seed)
initial_point = rng.random(ansatz.num_parameters)

backend = Aer.get_backend('aer_simulator')
quantum_instance = QuantumInstance(
    backend,
    shots=1024,
    seed_simulator=algorithm_globals.random_seed,
    seed_transpiler=algorithm_globals.random_seed
)
```