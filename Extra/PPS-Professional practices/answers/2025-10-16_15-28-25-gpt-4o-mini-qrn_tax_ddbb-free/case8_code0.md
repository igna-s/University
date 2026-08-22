| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import Aer` | Deprecation -> Import from qiskit.providers.aer is deprecated | IK | qiskit.providers.aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Updated -> qiskit.tools module is deprecated | IK | qiskit.utils | `from qiskit import QuantumInstance, algorithm_globals` |
| 3 | `from qiskit.circuit.library import TwoLocal` | (optional) | IK | qiskit.circuit.library |  |
| 4 | `from qiskit.opflow import Z, I, X` | (optional) | IK | qiskit.opflow |  |
| 5 | `import numpy as np` | (optional) | IK | numpy |  |
| 7 | `ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)` | (optional) | IK | TwoLocal |  |
| 11 | `backend = Aer.get_backend('qasm_simulator')` | Updated -> Use Operator from qiskit.quantum_info instead of BasicAer | IK | qiskit.quantum_info | `backend = Aer.get_backend('qasm_simulator')` |
| 12 | `quantum_instance = QuantumInstance(` | (optional) | IK | QuantumInstance |  |
| 13 | `    backend,` | (optional) | IK | backend |  |
| 14 | `    shots=1024,` | (optional) | IK | shots |  |
| 15 | `    seed_simulator=algorithm_globals.random_seed,` | (optional) | IK | random_seed |  |
| 16 | `    seed_transpiler=algorithm_globals.random_seed` | (optional) | IK | random_seed |  |
| 17 | `)` | (optional) | IK |  |  |

```python
from qiskit_aer import Aer
from qiskit import QuantumInstance, algorithm_globals
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