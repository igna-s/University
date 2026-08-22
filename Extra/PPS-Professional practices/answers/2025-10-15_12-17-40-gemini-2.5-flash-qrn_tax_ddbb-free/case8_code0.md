| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | qrn_tax_ddbb--0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> Deprecation of certain tools in qiskit.utils | qrn_tax_ddbb--4f791e8e-887c-47d9-80fa-50227b769092 | qiskit.utils.QuantumInstance | (Remove import and usage) |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> Deprecation of certain tools in qiskit.utils | qrn_tax_ddbb--4f791e8e-887c-47d9-80fa-50227b769092 | qiskit.utils.algorithm_globals | (Remove import and usage, replace with `numpy.random`) |
| 3 | `from qiskit.circuit.library import TwoLocal` | (optional) Changed -> Importing `TwoLocal` | IK | qiskit.circuit.library.TwoLocal | `from qiskit.circuit.library import NLocal` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> Deprecation of implicit conversion from BaseOperator to SparsePauliOp | qrn_tax_ddbb--b04b3fd0-03ff-4ee8-b78b-a5219681461e | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Deprecation -> Deprecation of implicit conversion from BaseOperator to SparsePauliOp | qrn_tax_ddbb--b04b3fd0-03ff-4ee8-b78b-a5219681461e | qiskit.opflow operators | `hamiltonian = SparsePauliOp('ZI') + SparsePauliOp('XX')` |
| 9 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | Deprecation -> Deprecation of certain tools in qiskit.utils | qrn_tax_ddbb--4f791e8e-887c-47d9-80fa-50227b769092 | algorithm_globals.random | `initial_point = np.random.random(ansatz.num_parameters)` |
| 11 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Deprecation of qiskit.Aer object | qrn_tax_ddbb--0771d384-706f-40c0-818d-20a4b728e9a2 | Aer.get_backend | `backend = AerSimulator()` |
| 12 | `quantum_instance = QuantumInstance(` | Deprecation -> Deprecation of certain tools in qiskit.utils | qrn_tax_ddbb--4f791e8e-887c-47d9-80fa-50227b769092 | QuantumInstance | (Remove code block as QuantumInstance is deprecated) |


```python
from qiskit_aer import AerSimulator
from qiskit.circuit.library import NLocal
from qiskit.quantum_info import SparsePauliOp
import numpy as np

hamiltonian = SparsePauliOp('ZI') + SparsePauliOp('XX')
num_qubits = 2
ansatz = NLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = np.random.random(ansatz.num_parameters)

backend = AerSimulator()
# QuantumInstance is deprecated. Configuration parameters like shots, seed_simulator,
# and seed_transpiler are now passed directly to the backend's run method or configured on the simulator.
# For example: backend.run(circuit, shots=1024, seed_simulator=seed_value, seed_transpiler=seed_value)
```