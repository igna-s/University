| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module has been deprecated. | Internal Knowledge | qiskit.opflow | `from qiskit.quantum_info import Pauli, SparsePauliOp` |
| 10 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> The `qiskit.opflow.PauliSumOp` class has been deprecated. | Internal Knowledge | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 12 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` is deprecated. Use `QiskitEstimator` instead. | Internal Knowledge | BackendEstimator | `estimator = QiskitEstimator(` |
| 14 | `options={"shots": 1024}` | Deprecation -> The `options` parameter for `BackendEstimator` has been removed. Options should be set directly on the estimator object. | Internal Knowledge | options | `estimator.set_options(shots=1024)` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import QiskitEstimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar QiskitEstimator con backend directamente
backend = getBackend()
estimator = QiskitEstimator(
    backend=backend,
)
estimator.set_options(shots=1024)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```