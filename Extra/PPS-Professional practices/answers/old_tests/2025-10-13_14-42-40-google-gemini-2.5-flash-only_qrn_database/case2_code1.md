| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `qiskit.opflow` module is deprecated | * | f7bd1861-358a-4281-bb81-7ff574c97f70 | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> `BackendEstimator` is deprecated | * | 288d04c8-6ee9-4c44-aaee-f4479171adee | BackendEstimator | `from qiskit.primitives import Estimator` |
| 12 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated | * | f7bd1861-358a-4281-bb81-7ff574c97f70 | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 16 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` is deprecated | * | 288d04c8-6ee9-4c44-aaee-f4479171adee | BackendEstimator | `estimator = Estimator(` |


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
estimator = Estimator(
    backend=backend,
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```