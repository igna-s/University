| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 8 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Implicit conversion from a dense `BaseOperator` to a `SparsePauliOp` in `Estimator` observable arguments is deprecated | * | f7bd1861-358a-4281-bb81-7ff574c97f70 | Estimator.run() | `job = estimator.run([psi1], [SparsePauliOp(H1)], [theta1])` |


```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([psi1], [SparsePauliOp(H1)], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```