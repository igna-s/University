| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
|:----:|------|----------|-------------|-----------|----------|-------------|
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> qiskit.opflow module removed | * | Internal Knowledge | qiskit.opflow | Replace with `from qiskit.quantum_info import PauliSumOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> opflow Pauli operators removed | * | Internal Knowledge | hamiltonian | Replace with `hamiltonian = PauliSumOp.from_list([('ZI', 1), ('XX', 1)])` |

```python
from qiskit import Aer
from qiskit.utils import QuantumInstance, algorithm_globals
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import PauliSumOp
import numpy as np

hamiltonian = PauliSumOp.from_list([('ZI', 1), ('XX', 1)])
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = algorithm_globals.random.random(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
quantum_instance = QuantumInstance(
    backend,
    shots=1024,
    seed_simulator=algorithm_globals.random_seed,
    seed_transpiler=algorithm_globals.random_seed
)
```
