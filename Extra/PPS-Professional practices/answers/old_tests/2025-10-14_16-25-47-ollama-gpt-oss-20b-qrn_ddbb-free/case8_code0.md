| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> algorithm_globals.random is deprecated | IK | algorithm_globals.random | `rng = np.random.default_rng(algorithm_globals.random_seed)`<br>`initial_point = rng.random(ansatz.num_parameters)` |

```python
from qiskit import Aer
from qiskit.utils import QuantumInstance, algorithm_globals
from qiskit.circuit.library import TwoLocal
from qiskit.opflow import Z, I, X
import numpy as np

hamiltonian = (Z ^ I) + (X ^ X)
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
rng = np.random.default_rng(algorithm_globals.random_seed)
initial_point = rng.random(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
quantum_instance = QuantumInstance(
    backend,
    shots=1024,
    seed_simulator=algorithm_globals.random_seed,
    seed_transpiler=algorithm_globals.random_seed
)
```