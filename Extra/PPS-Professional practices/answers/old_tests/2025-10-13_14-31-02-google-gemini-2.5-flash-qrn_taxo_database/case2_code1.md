| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> `qiskit.opflow` module deprecated | * | c91fce4d-07c2-4e06-9535-0979959cf51b | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> BackendEstimator is deprecated | * | 693ae18e-44c4-46d9-85af-1a4bbac67b6f | BackendEstimator | `from qiskit.primitives import Estimator` |
| 12 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` deprecated | * | c91fce4d-07c2-4e06-9535-0979959cf51b | PauliSumOp.from_list | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 16 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` class deprecated | * | 693ae18e-44c4-46d9-85af-1a4bbac67b6f | BackendEstimator | `estimator = Estimator(` |


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