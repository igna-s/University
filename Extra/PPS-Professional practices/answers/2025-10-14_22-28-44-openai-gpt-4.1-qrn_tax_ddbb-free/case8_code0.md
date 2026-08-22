| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import Aer | Deprecation -> qiskit.Aer object deprecated | qrn_tax_ddbb-c02fdd64-b33a-477c-a00d-105424346f39 | qiskit.Aer | from qiskit_aer import Aer |
| 2 | from qiskit.utils import QuantumInstance, algorithm_globals | Deprecation -> QuantumInstance is deprecated | IK | QuantumInstance |  |
| 4 | from qiskit.opflow import Z, I, X | Deprecation -> qiskit.opflow removed | IK | qiskit.opflow |  |
| 9 | backend = Aer.get_backend('qasm_simulator') | Deprecation -> qiskit.Aer object deprecated | qrn_tax_ddbb-c02fdd64-b33a-477c-a00d-105424346f39 | qiskit.Aer | backend = Aer.get_backend('qasm_simulator') |
| 10 | quantum_instance = QuantumInstance( | Deprecation -> QuantumInstance is deprecated | IK | QuantumInstance |  |

```python
from qiskit_aer import Aer
from qiskit.utils import algorithm_globals
from qiskit.circuit.library import TwoLocal
import numpy as np

# NOTE: qiskit.opflow (Z, I, X) is removed in Qiskit 1.0.0.
# You may need to use qiskit.quantum_info.operators or convert to qiskit.primitives/qubit operators.

num_qubits = 2
ansatz = TwoLocal(num_qubits, rotation_blocks='ry', entanglement_blocks='cz', reps=1)
initial_point = algorithm_globals.random.random(ansatz.num_parameters)

backend = Aer.get_backend('qasm_simulator')
# NOTE: QuantumInstance is deprecated. Please update your code to use Qiskit Primitives with Estimator/Sampler and run backend jobs directly if needed.
```