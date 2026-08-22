| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated as of Qiskit 0.46 and will be removed in Qiskit 1.0. You should explicitly convert to a SparsePauliOp using SparsePauliOp.from_operator() instead. | qrn_notax_ddbb-6a782250-d3b0-4afa-a877-8432d57d59aa | | `job = estimator.run(psi1, H1, theta1)` |


```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run(psi1, H1, theta1)
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```