| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` |  Package move -> Package qiskit.Aer moved to qiskit.providers.aer | qrn_tax_ddbb-2e9968107b13f4a509b01a94db090a3e | qiskit.Aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The class `QuantumInstance` is deprecated | qrn_tax_ddbb-645ca37683c0367b5483a92495559911 | qiskit.utils.QuantumInstance |  |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Package move -> The qiskit.utils.algorithm_globals module has been migrated | qrn_tax_ddbb-fbb6c9c99b422348459a7855d4993848 | qiskit.utils.algorithm_globals | `from qiskit.primitives import Sampler` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Removal -> Remove algorithm_globals | qrn_tax_ddbb-e3559d8098ae3034a2294139a316c6c3 | qiskit.utils.algorithm_globals |  |
| 5 | `from qiskit.opflow import Z, I, X` | Package move ->  The qiskit.opflow module has been migrated to qiskit.quantum_info | qrn_tax_ddbb-3181f083b666544c7561015a66692992 | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 5 | `from qiskit.opflow import Z, I, X` | Deprecation -> `I`, `X`, `Y`, and `Z` are deprecated aliases for `Pauli('I')`, `Pauli('X')`, `Pauli('Y')`, and `Pauli('Z')` | qrn_tax_ddbb-2371312748b32076a84efb004589a348 | qiskit.opflow.primitive_ops |  |
| 5 | `from qiskit.opflow import Z, I, X` | Deprecation -> `^` operator between Pauli objects is deprecated. | qrn_tax_ddbb-ca7529446ef872874b01f4d420bea9bf | qiskit.opflow |  |
| 8 | `hamiltonian = (Z ^ I) + (X ^ X)` | Refactor -> Replace `Z ^ I` and `X ^ X` with `SparsePauliOp.from_list([(Z, 1), (I, 1)])` and `SparsePauliOp.from_list([(X, 1), (X, 1)])` respectively | IK | qiskit.opflow | `hamiltonian = SparsePauliOp.from_list([(("ZI"), 1), (("XX"), 1)])` |
| 11 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Removal -> Remove algorithm_globals | qrn_tax_ddbb-e3559d8098ae3034a2294139a316c6c3 | qiskit.utils.algorithm_globals | `initial_point = np.random.random(ansatz.num_parameters)` |
| 13 | `backend = Aer.get_backend('qasm_simulator')` | Package move -> Package qiskit.Aer moved to qiskit.providers.aer | qrn_tax_ddbb-2e9968107b13f4a509b01a94db090a3e | qiskit.Aer | `backend = Aer.get_backend('qasm_simulator')` |
| 14 | `quantum_instance = QuantumInstance(` | Deprecation -> The class `QuantumInstance` is deprecated | qrn_tax_ddbb-645ca37683c0367b5483a92495559911 | qiskit.utils.QuantumInstance |  |
| 14 | `quantum_instance = QuantumInstance(` | Replacement -> Replace QuantumInstance by Sampler | IK | qiskit.utils.QuantumInstance | `sampler = Sampler(run_options={"shots": 1024, "seed": 10598})` |
| 16 | `seed_simulator=algorithm_globals.random_seed,` | Removal -> Remove algorithm_globals | qrn_tax_ddbb-e3559d8098ae3034a2294139a316c6c3 | qiskit.utils.algorithm_globals |  |
| 17 | `seed_transpiler=algorithm_globals.random_seed` | Removal -> Remove algorithm_globals | qrn_tax_ddbb-e3559d8098ae3034a2294139a316c6c3 | qiskit.utils.algorithm_globals |  |

```python
from qiskit_aer import Aer
from qiskit.primitives import Sampler
from qiskit.circuit.library import TwoLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = SparsePauliOp.from_list([(("ZI"), 1), (("XX"), 1)])
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.random(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
sampler = Sampler(run_options={"shots": 1024, "seed": 10598})
```