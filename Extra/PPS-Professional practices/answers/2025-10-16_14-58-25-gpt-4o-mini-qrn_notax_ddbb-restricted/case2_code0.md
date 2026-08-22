| Line | Code                                                        | Scenario                                                                                                                      | Reference                                      | Artifact                                                  | Refactoring                                                                 |
| :--: | :-------------------------------------------------------   | :-------                                                                                                                    | :-------                                      | :-------                                                  | :----------                                                               |
| 1    | `from qiskit.quantum_info import SparsePauliOp`           | Deprecation -> Implicit conversion from a dense BaseOperator to SparsePauliOp deprecated                                   | qrn_notax_ddbb-6a782250-d3b0-4afa-a877-8432d57d59aa | qiskit.quantum_info                                      | `from qiskit.quantum_info import SparsePauliOp`                        |
| 2    | `from qiskit.primitives import Estimator`                  | Deprecation -> Estimator as a high-level wrapper around running circuits          | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.primitives                                         | `from qiskit.primitives import BackendSampler`                          |
| 3    | `from qiskit.circuit.library import RealAmplitudes`       | Deprecation -> The constructor RealAmplitudes is replaced with a new library's function                                  | IK                                            | qiskit.circuit.library                                    | `from qiskit.circuit.library import RealAmplitudes`                     |
| 5    | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Using a PauliList as an observable implicitly converted to a SparsePauliOp deprecated | qrn_notax_ddbb-2125b2ad-3e2e-494b-b0de-816d0703f19c | SparsePauliOp                                            | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])`             |
| 6    | `estimator = Estimator()`                                  | Updated -> Immediate use of Sampler replaces Estimator for job execution                                                   | IK                                            | Estimator                                                 | `estimator = BackendSampler(backend)`                                   |
| 10   | `job_result = job.result()`                               | Updated -> job.result() usage in different context since Estimator replaced with BackendSampler function                  | IK                                            | job                                                      | `job_result = job.result()`                                               |
| 11   | `print(f"The primitive-job finished with result {job_result}")` | No updates needed for print function                                                                                       | IK                                            | result                                                   | `print(f"The primitive-job finished with result {job_result}")`        |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import BackendSampler
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

sampler = BackendSampler(backend)
job = sampler.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```