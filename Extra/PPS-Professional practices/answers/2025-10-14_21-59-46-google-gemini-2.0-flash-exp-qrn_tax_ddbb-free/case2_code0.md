| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.primitives import Estimator` | Deprecation -> Primitives have been replaced by Estimator and Sampler in qiskit.providers | qrn_tax_ddbb-24a7c72e7ca85b8488274e99443e0979 | qiskit.primitives | `from qiskit.providers import Estimator` |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.providers import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator()
job = estimator.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```