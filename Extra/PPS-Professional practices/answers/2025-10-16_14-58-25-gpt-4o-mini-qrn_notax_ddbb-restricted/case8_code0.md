| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0 | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.providers.aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Updated -> QuantumInstance class is moved | IK | qiskit.utils | `from qiskit.utils import QuantumInstance, algorithm_globals` |
| 3 | `from qiskit.circuit.library import TwoLocal` | Updated -> TwoLocal class is moved | IK | qiskit.circuit.library | `from qiskit.circuit.library import TwoLocal` |
| 4 | `from qiskit.opflow import Z, I, X` | Updated -> Z, I, X classes are moved | IK | qiskit.opflow | `from qiskit.opflow import Z, I, X` |
| 5 | `import numpy as np` | - | IK | numpy | - |
| 7 | `num_qubits = 2` | - | IK | - | - |
| 8 | `ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)` | - | IK | - | - |
| 9 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | - | IK | - | - |
| 11 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend() method has changed | qrn_notax_ddbb-98ed0e4a-c3d2-4c4f-93a7-42ebe62e7869 | Aer | `backend = Aer.get_backend('qasm_simulator')` |
| 12 | `quantum_instance = QuantumInstance(backend, shots=1024, seed_simulator=algorithm_globals.random_seed, seed_transpiler=algorithm_globals.random_seed)` | - | IK | QuantumInstance | - |

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