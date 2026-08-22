| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `qiskit.opflow` module is deprecated | IK | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 11 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated | IK | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 20 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Implicit conversion from `BaseOperator` to `SparsePauliOp` is deprecated | b04b3fd0-03ff-4ee8-b78b-a5219681461e | Estimator.run() | `job = estimator.run([psi1], [H1], [theta1])` |
| 20 | `job = estimator.run([psi1], [H1], [theta1])` | Deprecation -> Using a `PauliList` as an observable that is implicitly converted to a `SparsePauliOp` with coefficients 1 when calling `Estimator.run()` is deprecated. | 039bc9ef-72bf-4376-9047-3e418906d0e0 | Estimator.run() | `job = estimator.run([psi1], [H1], [theta1])` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import BackendEstimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
estimator = BackendEstimator(
    backend=backend,
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```