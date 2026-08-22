| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.circuit.library import TwoLocal` | Deprecation -> TwoLocal removed from qiskit.circuit.library in 1.0.0 | qrn_tax_ddbb--98c7dcca-893a-41cb-9efd-1034455d5c12 | TwoLocal | `from qiskit.circuit import TwoLocal` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> qiskit.opflow removed in 1.0.0 | qrn_tax_ddbb--ed4b8d06-92f3-4f65-8729-b506ebed9393 | qiskit.opflow | Replace with Pauli operators from qiskit.quantum_info: `from qiskit.quantum_info import Pauli, SparsePauliOp` and later construct Hamiltonian as `hamiltonian = SparsePauliOp.from_list([("ZI", 1.0), ("XX", 1.0)])` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> opflow arithmetic for Hamiltonians removed in 1.0.0 | qrn_tax_ddbb--ed4b8d06-92f3-4f65-8729-b506ebed9393 | qiskit.opflow | `hamiltonian = SparsePauliOp.from_list([("ZI", 1.0), ("XX", 1.0)])` |

```python
from qiskit import Aer
from qiskit.utils import QuantumInstance, algorithm_globals
from qiskit.circuit import TwoLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = SparsePauliOp.from_list([("ZI", 1.0), ("XX", 1.0)])
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