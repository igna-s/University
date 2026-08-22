| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit.quantum_info import SparsePauliOp` | Deprecation -> Implicit conversion from BaseOperator to SparsePauliOp in Estimator observable arguments is deprecated | qrn_tax_ddbb-39ffe0af-aa04-4b57-bb2f-69c83c0c4472 | Estimator.run() | `Estimator.run(SparsePauliOp.from_operator(BaseOperator))` |
| 2 | `from qiskit.primitives import Estimator` | New module -> BasicProvider and BasicSimulator replaces Basicaer | qrn_tax_ddbb-876953c5-8f2d-41de-a547-a72fe2a408ae | BasicProvider | `from qiskit.providers.basic_provider import BasicProvider` |
| 3 | `from qiskit.circuit.library import RealAmplitudes` | Deprecation -> RealAmplitudes library may have been moved | IK | RealAmplitudes | |
| 5 | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Implicit conversion from BaseOperator to SparsePauliOp in Estimator observable arguments is deprecated | qrn_tax_ddbb-39ffe0af-aa04-4b57-bb2f-69c83c0c4472 | SparsePauliOp | `SparsePauliOp.from_operator()` |
| 8 | `estimator = Estimator()` | Structural change -> Migration: Estimator class replaces the deprecated executor | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | Estimator | `sampler = BackendSampler(backend)` | 
| 9 | `job = estimator.run([psi1], [H1], [theta1])` | New functionality -> BackendSampler replaces execute | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | BackendSampler | `job = sampler.run(circuit)` |
| 10 | `job_result = job.result()` | Structural change -> Job management | IK | result | |
| 11 | `print(f"The primitive-job finished with result {job_result}")` | | IK | print | |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit.providers.basic_provider import BasicProvider
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_operator(SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]))
theta1 = [0, 1, 1, 2, 3, 5]

estimator = BackendSampler(backend)
job = estimator.run([psi1], [H1], [theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```