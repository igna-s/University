| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated. | qrn_tax_ddbb-084696d9-2c75-437a-8e84-96506e6766aa | qiskit.providers.aer | `from qiskit_aer import Aer` |
| 7 | `backend = Aer.get_backend('qasm_simulator')` | Structural change -> Migration: basicaer simulators to basic_provider. | qrn_tax_ddbb-34bad2ff-65a5-4e60-872f-261acff55134 | BasicAer | `from qiskit.providers.basic_provider import BasicProvider\nbackend = BasicProvider().get_backend("basic_simulator")` |
| 8 | `quantum_instance = QuantumInstance(` | Deprecated -> Execute is deprecated for use cases. | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | QuantumInstance | `quantum_instance = QuantumInstance(backend, shots=1024, seed_simulator=algorithm_globals.random_seed, seed_transpiler=algorithm_globals.random_seed)` |

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

backend = BasicProvider().get_backend("basic_simulator")
quantum_instance = QuantumInstance(
    backend,
    shots=1024,
    seed_simulator=algorithm_globals.random_seed,
    seed_transpiler=algorithm_globals.random_seed
)
```