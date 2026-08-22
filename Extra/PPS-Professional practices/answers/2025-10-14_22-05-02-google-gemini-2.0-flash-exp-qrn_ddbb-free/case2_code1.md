| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by the `qiskit.quantum_info` module and new circuit primitives. For more information, see https://ibm.co/3YjEzz3. | qrn_ddbb-7461b6 | qiskit.opflow |  |
| 2 | `from qiskit.opflow import PauliSumOp` | Replacement -> Use `SparsePauliOp` instead of `PauliSumOp`. | qrn_ddbb-7461b6 | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> The class `qiskit.primitives.backend_estimator.BackendEstimator` is deprecated as of qiskit-terra 0.24.0. It will be removed no earlier than 3 months after the release date. For code migration guidelines, visit https://qisk.it/primitive_migration. | qrn_ddbb-169366 | BackendEstimator |  |
| 3 | `from qiskit.primitives import BackendEstimator` | Replacement -> Use `Estimator` instead of `BackendEstimator`. | qrn_ddbb-169366 | BackendEstimator | `from qiskit.primitives import Estimator` |
| 10 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Replacement -> The class `PauliSumOp` is deprecated and replaced with the class `SparsePauliOp`. | qrn_ddbb-7461b6 | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 14 | `estimator = BackendEstimator(` | Replacement -> The class `qiskit.primitives.backend_estimator.BackendEstimator` is deprecated as of qiskit-terra 0.24.0. It will be removed no earlier than 3 months after the release date. For code migration guidelines, visit https://qisk.it/primitive_migration. | qrn_ddbb-169366 | BackendEstimator | `estimator = Estimator(` |

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