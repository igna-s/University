| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.primitives import Estimator` | Deprecation -> The class `qiskit.primitives.Estimator` is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by the class `qiskit.quantum_simulator.primitives.Estimator`. | qrn_ddbb-c98f429a1f1e498fa4f06254a6261628 | qiskit.primitives.Estimator | `from qiskit.quantum_simulator import Estimator` |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.quantum_simulator import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```