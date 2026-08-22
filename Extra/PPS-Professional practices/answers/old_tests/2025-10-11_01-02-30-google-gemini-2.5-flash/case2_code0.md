| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `estimator = Estimator()` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated as of Qiskit 0.46 and will be removed in Qiskit 1.0. You should explicitly convert to a SparsePauliOp using SparsePauliOp.from_operator() instead. | 67dae5d4-ce07-4118-976c-520108bdc74c | Estimator | `from qiskit.primitives import Estimator` |
| 9 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | 9f2deafd-17d5-462f-b55d-2fb91b5f4004 | Estimator.run() | `job = estimator.run([psi1], [H1], [theta1])` |


```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```