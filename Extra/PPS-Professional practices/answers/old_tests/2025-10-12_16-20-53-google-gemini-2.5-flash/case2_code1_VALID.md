| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow.PauliSumOp` class is deprecated. | * | Internal Knowledge | `qiskit.opflow.PauliSumOp` | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> The `qiskit.primitives.BackendEstimator` class is deprecated. | * | Internal Knowledge | `qiskit.primitives.BackendEstimator` | `from qiskit.primitives import Estimator` |
| 11 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> The `PauliSumOp` class and its methods are deprecated. | * | 35324c6d-04f1-419a-8cec-24cf2fc6c21c | `PauliSumOp.from_list` | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 15 | `estimator = BackendEstimator(` | Deprecation -> The `BackendEstimator` class is deprecated. | * | Internal Knowledge | `BackendEstimator` | `estimator = Estimator(` |
| 16 | `backend=backend,` | Update -> The `Estimator` constructor no longer accepts a `backend` argument directly. | * | Internal Knowledge | `BackendEstimator` constructor `backend` argument | |
| 20 | `job = estimator.run([psi1], [H1], [theta1])` | Update -> `Estimator.run()` now accepts the `backend` argument directly. | * | Internal Knowledge | `Estimator.run` | `job = estimator.run([psi1], [H1], [theta1], backend=backend)` |


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
estimator = Estimator(
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1], backend=backend)
result = job.result()

print(f"Expectation value: {result.values[0]}")
```