| Line | Code                                                            | Scenario                                                                                                                                                          | Reference                                      | Artifact           | Refactoring                                                                                                                        |
|------|-----------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|--------------------|-------------------------------------------------------------------------------------------------------------------------------------|
| 1    | `from qiskit.quantum_info import SparsePauliOp`               | Deprecation -> The import from qiskit.quantum_info deprecated                                                                                                   | qrn_notax_ddbb--6a782250-d3b0-4afa-a877-8432d57d59aa | qiskit.quantum_info | `from qiskit.quantum_info import SparsePauliOp`                                                                                   |
| 2    | `from qiskit.primitives import Estimator`                      | Deprecation -> The import from qiskit.primitives deprecated                                                                                                    | qrn_notax_ddbb--2125b2ad-3e2e-494b-b0de-816d0703f19c | qiskit.primitives  | `from qiskit.primitives import Estimator`                                                                                         |
| 3    | `from qiskit.circuit.library import RealAmplitudes`           | Deprecation -> The import from qiskit.circuit.library deprecated                                                                                              | qrn_notax_ddbb--f4c93c55-92c4-4888-93f1-4daec7c357bb | qiskit.circuit.library | `from qiskit.circuit.library import RealAmplitudes`                                                                              |
| 5    | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated                                   | qrn_notax_ddbb--6a782250-d3b0-4afa-a877-8432d57d59aa | SparsePauliOp      | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])`                                                                |
| 8    | `job = estimator.run([psi1], [H1], [theta1])`                 | Updated -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated | qrn_notax_ddbb--2125b2ad-3e2e-494b-b0de-816d0703f19c | Estimator          | `job = estimator.run([psi1], [SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])], [theta1])`                           |
| 9    | `job_result = job.result()`                                    |                                                                                                                                                                  | IK                                             | job                |                                                                                                                                     |
| 10   | `print(f"The primitive-job finished with result {job_result}")`|                                                                                                                                                                  | IK                                             | print              |                                                                                                                                     |

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