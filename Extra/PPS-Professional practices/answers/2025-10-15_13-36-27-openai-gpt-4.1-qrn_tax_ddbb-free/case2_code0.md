| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 6 | `estimator = Estimator()` | API Change -> Estimator instantiation now requires specifying a backend (Simulator or Quantum device) | qrn_tax_ddbb--afc7d3b3-4267-4305-9017-a66b05d0fa7d | Estimator | `estimator = Estimator(backend="statevector_simulator")` |
| 7 | `job = estimator.run([psi1], [H1], [theta1])` | API Change -> Estimator.run() argument format has changed to not require explicit parameter lists; triplet ([circuits], [observables], [parameters]) is replaced with list of EstimatorInputs or parallel lists | qrn_tax_ddbb--eea17e8c-4a38-4f0c-a38c-1c0147adba9f | Estimator.run | `job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])` |

```python  
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from qiskit.circuit.library import RealAmplitudes

psi1 = RealAmplitudes(num_qubits=2, reps=2)
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])
theta1 = [0, 1, 1, 2, 3, 5]

estimator = Estimator(backend="statevector_simulator")
job = estimator.run(circuits=[psi1], observables=[H1], parameter_values=[theta1])
job_result = job.result()
print(f"The primitive-job finished with result {job_result}")
```