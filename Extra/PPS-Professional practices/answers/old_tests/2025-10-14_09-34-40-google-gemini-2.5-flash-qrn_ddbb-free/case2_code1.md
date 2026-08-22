| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module is deprecated. | Internal Knowledge | `qiskit.opflow.PauliSumOp` | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> `BackendEstimator` is deprecated. | Internal Knowledge | `qiskit.primitives.BackendEstimator` | `from qiskit.primitives import Estimator` |
| 10 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated. | Internal Knowledge | `PauliSumOp` | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 14 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` constructor is deprecated. | Internal Knowledge | `BackendEstimator` | `estimator = Estimator()` |
| 15 | `backend=backend,` | Deprecation -> The `backend` parameter in `BackendEstimator` is no longer supported in `Estimator`. | Internal Knowledge | `backend` | |
| 16 | `options={"shots": 1024}` | Update -> `options` parameter is set on the `Estimator` object directly. | Internal Knowledge | `options` | `estimator.options.shots = 1024` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar Estimator
backend = getBackend()
estimator = Estimator()
estimator.options.shots = 1024

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```