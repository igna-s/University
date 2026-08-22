| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `qiskit.opflow` module removed | * | internal | `qiskit.opflow.PauliSumOp` | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> `BackendEstimator` replaced by `Estimator` | * | internal | `qiskit.primitives.BackendEstimator` | `from qiskit.primitives import Estimator` |
| 11 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` removed, use `SparsePauliOp` | * | internal | `PauliSumOp` | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 14 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` replaced by `Estimator` | * | internal | `BackendEstimator` | `estimator = Estimator(` |
| 15 | `options={"shots": 1024}  # Configurar shots aquí` | Change -> `options` argument for `shots` moved to backend configuration | * | internal | `options` | `backend.options.shots = 1024` |


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

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
backend.options.shots = 1024  # Configurar shots aquí
estimator = Estimator(
    backend=backend
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")

```