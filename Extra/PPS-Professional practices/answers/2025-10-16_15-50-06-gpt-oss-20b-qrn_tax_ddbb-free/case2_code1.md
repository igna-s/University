| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> BackendEstimator is deprecated in Qiskit 1.0.0 | IK | BackendEstimator | `from qiskit.primitives.estimator import Estimator` |
| 15 | `estimator = BackendEstimator(` | Deprecation -> BackendEstimator replaced by Estimator | IK | BackendEstimator | `estimator = Estimator(` |
| 17 | `options={"shots": 1024}  # Configurar shots aquí` | Deprecation -> `options` kwarg replaced by `backend_options` | IK | options | `backend_options={"shots": 1024}` |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.opflow import PauliSumOp
from qiskit.primitives.estimator import Estimator
from utils import getBackend

psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

backend = getBackend()
estimator = Estimator(
    backend=backend,
    backend_options={"shots": 1024}
)

job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```
