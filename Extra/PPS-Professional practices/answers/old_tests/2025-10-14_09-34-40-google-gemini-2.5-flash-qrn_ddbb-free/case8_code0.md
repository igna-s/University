| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> The Aer module is deprecated. | qrn_ddbb-5099 | qiskit.Aer | `from qiskit.providers.basic_provider import BasicSimulator` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The QuantumInstance class is deprecated. | qrn_ddbb-e9f0 | qiskit.utils.QuantumInstance | `from qiskit.primitives import Sampler` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The algorithm_globals class is deprecated. | qrn_ddbb-8d5f | qiskit.utils.algorithm_globals | |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> The entire Opflow module is deprecated. | qrn_ddbb-8bfb | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> Opflow operators like Z, I, X and their operations are deprecated. | qrn_ddbb-8bfb | (Z ^ I) + (X ^ X) | `hamiltonian = SparsePauliOp("ZI") + SparsePauliOp("XX")` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> algorithm_globals.random is deprecated. | qrn_ddbb-8d5f | algorithm_globals.random.random | `initial_point = np.random.default_rng().random(ansatz.num_parameters)` |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend is deprecated. | qrn_ddbb-5099 | Aer.get_backend | `backend = BasicSimulator()` |
| 13 | `quantum_instance = QuantumInstance(` | Deprecation -> The QuantumInstance class is deprecated. | qrn_ddbb-e9f0 | QuantumInstance | `sampler = Sampler(` |
| 15 | `shots=1024,` | Deprecation -> shots parameter in QuantumInstance is deprecated. | qrn_ddbb-e9f0 | shots | `options={"shots": 1024,` |
| 16 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> seed_simulator in QuantumInstance is deprecated. | qrn_ddbb-e9f0 | seed_simulator | `seed_simulator": 1234,` |
| 17 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> seed_transpiler in QuantumInstance is deprecated. | qrn_ddbb-e9f0 | seed_transpiler | `seed_transpiler": 1234}` |


```python
from qiskit.providers.basic_provider import BasicSimulator
from qiskit.primitives import Sampler
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = SparsePauliOp("ZI") + SparsePauliOp("XX")
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.default_rng().random(ansatz.num_parameters)

backend = BasicSimulator()
sampler = Sampler(
    backend=backend,
    options={"shots": 1024, "seed_simulator": 1234, "seed_transpiler": 1234}
)
```