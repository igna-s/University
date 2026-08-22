| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module is deprecated | IK | qiskit.opflow.PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> `BackendEstimator` has been deprecated. | IK | BackendEstimator | `from qiskit.primitives import Estimator` |
| 12 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated, and implicit conversion from `PauliList` to `SparsePauliOp` in Estimator observable arguments is deprecated. | 2125b2ad-3e2e-494b-b0de-816d0703f19c | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 16 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` is deprecated. | IK | BackendEstimator | `estimator = Estimator(` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from utils import getBackend

psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

backend = getBackend()
estimator = Estimator(
    backend=backend,
    options={"shots": 1024}
)

job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```