| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit.Aer | `from qiskit_aer import Aer` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | QuantumInstance, algorithm_globals | `from qiskit.utils import algorithm_globals` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | qiskit.opflow | |
| 11 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend | `backend = AerSimulator()` |
| 12 | `quantum_instance = QuantumInstance(` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | QuantumInstance | |
| 13 | `backend,` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | backend | |
| 14 | `shots=1024,` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | shots | |
| 15 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | seed_simulator | |
| 16 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> The following tools in qiskit.utils have been deprecated: Utils in qiskit.utils.arithmetic Utils in qiskit.utils.circuit_utils Utils in qiskit.utils.entangler_map Utils in qiskit.utils.name_unnamed_args These functions were used exclusively in the context of qiskit.algorithms and qiskit.opflow, and will be removed following the removals of qiskit.algorithms and qiskit.opflow in Qiskit 1.0. | qrn_notax_ddbb-86365b6b-cadf-4648-9399-b34d06c20ecd | seed_transpiler | |

```python
from qiskit_aer import AerSimulator
from qiskit.utils import algorithm_globals
from qiskit.circuit.library import TwoLocal
import numpy as np

hamiltonian = (np.kron([[1, 0], [0, -1]], np.eye(2))) + (np.kron([[0, 1], [1, 0]], [[0, 1], [1, 0]]))
num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = algorithm_globals.random.random(ansatz.num_parameters)

backend = AerSimulator()

```