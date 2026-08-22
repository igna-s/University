| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.quantum_info import SparsePauliOp` | (optional) Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | * | 35324c6d-04f1-419a-8cec-24cf2fc6c21c | Estimator.run() | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 8 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated. You should explicitly convert to a SparsePauliOp using SparsePauliOp.from_operator() instead. | 26 | 50c79ea1-b84f-4238-980b-cb70ef9b9876 | Estimator.run() | `job = estimator.run([psi1], [H1], [theta1])` |


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