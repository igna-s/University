| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> The `Aer` object is deprecated in `qiskit`. | qrn_tax_ddbb-0771d384-706f-40c0-818d-20a4b728e9a2 | `qiskit.Aer` | `from qiskit_aer import Aer` |

```python
from qiskit_aer import Aer
from qiskit.utils import QuantumInstance, algorithm_globals
from qiskit.circuit.library import TwoLocal
from qiskit.opflow import Z, I, X
import numpy as np

hamiltonian = (Z ^ I) + (X ^ X)
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
