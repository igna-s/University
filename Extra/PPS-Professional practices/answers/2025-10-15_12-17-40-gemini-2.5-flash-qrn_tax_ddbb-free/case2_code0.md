| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `job = estimator.run([psi1], [H1], [theta1])` | Updated -> The Estimator.run method arguments have been updated to use keyword arguments `circuits`, `observables`, and `parameter_values`. | qrn_tax_ddbb--f05566f1-399a-4c2c-8d12-6a75f284e6ae | Estimator.run | `job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])` |


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