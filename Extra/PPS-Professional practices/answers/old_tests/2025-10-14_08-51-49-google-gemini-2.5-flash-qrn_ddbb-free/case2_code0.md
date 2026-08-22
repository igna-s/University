| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `estimator = Estimator()` | Deprecation -> The Estimator() class is deprecated. | Internal Knowledge | Estimator | `estimator = Estimator()` |
| 9 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> The Estimator.run() method is deprecated. | Internal Knowledge | Estimator.run | `job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])` |


```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```