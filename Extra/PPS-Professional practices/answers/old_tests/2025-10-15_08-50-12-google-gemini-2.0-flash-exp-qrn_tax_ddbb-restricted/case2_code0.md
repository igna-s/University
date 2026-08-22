| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.primitives import Estimator` | Deprecation -> The class `qiskit.primitives.Estimator` is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by the class `qiskit.quantum_runtime.EstimatorV2`. | qrn_tax_ddbb-78899809-539c-4274-9487-608649f8470b | qiskit.primitives.Estimator | `from qiskit_ibm_runtime import EstimatorV2 as Estimator` |
| 5 | `psi1 = RealAmplitudes(num_qubits=2, reps=2)` | Parameter Default Value Changed -> The default value of the `reps` parameter of the `RealAmplitudes` class has changed from 3 to 1. | qrn_tax_ddbb-07448108-b71e-4c8e-8ff1-4596c447a804 | RealAmplitudes | `psi1 = RealAmplitudes(num_qubits=2, reps=2)` |
| 10 | `estimator = Estimator()` |  Parameter Changed -> The default value of the `options` parameter of the constructor `Estimator` has been changed.  | qrn_tax_ddbb-70a5e673-3568-4c03-a275-3505f940f644 | qiskit.primitives.Estimator | `estimator = Estimator(options={"backend": "ibmq_qasm_simulator"})` |
| 10 | `estimator = Estimator()` | Deprecation -> The class `qiskit.primitives.Estimator` is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by the class `qiskit.quantum_runtime.EstimatorV2`. | qrn_tax_ddbb-78899809-539c-4274-9487-608649f8470b | qiskit.primitives.Estimator | `estimator = Estimator()` |
| 11 | `job = estimator.run([psi1], [H1], [theta1])` | Parameter value changed -> The `run` method of the class `Estimator` will now return an instance of the class `EstimatorResult` instead of an instance of the class `PrimitiveJob`. | qrn_tax_ddbb-894e449a-906f-441f-8bd4-007585f2af71 | qiskit.primitives.Estimator | `job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])` |
| 12 | `job_result = job.result()` | Removed -> The `result()` method has been removed from the `BaseJob` class. | qrn_tax_ddbb-29509112-ca65-463d-a956-01f61450a55a | qiskit.providers.BaseJob | `job_result = job` |

```python
from qiskit.quantum_info import SparsePauliOp
from qiskit_ibm_runtime import EstimatorV2 as Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator(options={"backend": "ibmq_qasm_simulator"})
job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])
job_result = job
print(f"The primitive-job finished with result {job_result}")
```