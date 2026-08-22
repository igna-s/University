| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by `qiskit.quantum_info`, `qiskit.circuit.library`, and `qiskit.algorithms` | qrn_tax_ddbb-7a744492-338d-45e8-a558-2559ec354843 | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 2 | `from qiskit.opflow import PauliSumOp` | Class rename -> `PauliSumOp` is renamed to `SparsePauliOp` | qrn_tax_ddbb-aa2144ca-a585-4d96-b771-588f74b1a691 | PauliSumOp | `SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> Class `BackendEstimator` is deprecated and will be removed no earlier than 3 months after the release date. It is replaced by the class `Estimator`, which is part of the new primitives. | qrn_tax_ddbb-3c866a77-b729-4723-9ab3-5484199862a4 | BackendEstimator | `from qiskit.primitives import Estimator` |
| 3 | `from qiskit.primitives import BackendEstimator` | Class rename -> The class `BackendEstimator` is replaced by the class `Estimator` | qrn_tax_ddbb-2ca7093c-753e-4822-9026-39244d591889 | BackendEstimator | `Estimator` |
| 7 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Class rename -> `PauliSumOp` is renamed to `SparsePauliOp` | qrn_tax_ddbb-aa2144ca-a585-4d96-b771-588f74b1a691 | PauliSumOp |  |
| 7 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Method replacement -> The `from_list` method is deprecated. Use `from_sparse_list` instead. | qrn_tax_ddbb-550e0ceb-56a4-4483-8041-72178c645d51 | from_list | `.from_sparse_list` |
| 11 | `estimator = BackendEstimator(` | Class rename -> The class `BackendEstimator` is replaced by the class `Estimator` | qrn_tax_ddbb-2ca7093c-753e-4822-9026-39244d591889 | BackendEstimator | `estimator = Estimator(` |
| 12 | `backend=backend,` | Parameter Default value changed -> The default value of the `backend` parameter of `Estimator` is now `None`. | qrn_tax_ddbb-579af434-9ca6-41c2-8962-b1f138a4a016 | backend |  |
| 11 | `estimator = BackendEstimator(` |  Deprecated -> the class `Estimator` no longer has the `backend` parameter. | qrn_tax_ddbb-9678224c-1966-41b1-a6ff-f56359d53987 | backend |  |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_sparse_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
estimator = Estimator(
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```