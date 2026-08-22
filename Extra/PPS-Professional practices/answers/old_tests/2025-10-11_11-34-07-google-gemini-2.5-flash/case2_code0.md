| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.quantum_info import SparsePauliOp` | (optional) Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | * | 67e0eee6-39d8-474b-a93e-924055dc3921 | SparsePauliOp | `from qiskit.quantum_info import SparsePauliOp` |
| 2 | `from qiskit.primitives import Estimator` | (optional) Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | * | 67e0eee6-39d8-474b-a93e-924055dc3921 | Estimator | `from qiskit.primitives import Estimator` |


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