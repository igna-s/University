| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `PauliSumOp` is deprecated | qrn_tax_ddbb-f8f5e7ed-990e-4a31-9035-2032af8be117 | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> The `qiskit.primitives.BackendEstimator` class is deprecated. | IK | BackendEstimator | `from qiskit_aer.primitives import Estimator` |
| 11 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated | qrn_tax_ddbb-f8f5e7ed-990e-4a31-9035-2032af8be117 | PauliSumOp.from_list | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 15 | `estimator = BackendEstimator(` | Deprecation -> The `qiskit.primitives.BackendEstimator` class is deprecated. | IK | BackendEstimator | `estimator = Estimator(` |
| 16 | `backend=backend,` | Deprecation -> Backend parameter is deprecated for Estimator | qrn_tax_ddbb-039bc9ef-72bf-4376-9047-3e418906d0e0 | BackendEstimator | |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit_aer.primitives import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
estimator = Estimator(
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1], backend=backend)
result = job.result()

print(f"Expectation value: {result.values[0]}")
```