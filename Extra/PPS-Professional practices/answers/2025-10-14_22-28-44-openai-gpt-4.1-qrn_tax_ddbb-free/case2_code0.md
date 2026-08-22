| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 7 | `job = estimator.run([psi1], [H1], [theta1])` | API Update -> Estimator.run() parameter signature changed (circuits, observables, parameter_values) to (circuits, observables, parameter_values=None); multiple parameters should be zipped in tuples | qrn_tax_ddbb-597f98cddb30c7d6ea741e1cf04cee | Estimator.run | `job = estimator.run([(psi1, H1, theta1)])` |

```python  
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([(psi1, H1, theta1)])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```