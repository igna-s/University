| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.primitives import Estimator | Move -> Estimator class has moved from qiskit.primitives to qiskit.primitives.estimator | qrn_notax_ddbb--65f10f31-a4ee-48c7-967c-1aecba4fdeb1 | qiskit.primitives.Estimator | from qiskit.primitives.estimator import Estimator |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives.estimator import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```