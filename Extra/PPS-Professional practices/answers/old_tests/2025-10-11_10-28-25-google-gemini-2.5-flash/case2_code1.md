| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `qiskit.opflow` module is deprecated | * | 67e0eee6-39d8-474b-a93e-924055dc3921 | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 12 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated | * | 67e0eee6-39d8-474b-a93e-924055dc3921 | PauliSumOp.from_list | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.primitives import BackendEstimator
from qiskit.quantum_info import SparsePauliOp
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