| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> BackendEstimator is deprecated | IK | BackendEstimator | `from qiskit.primitives import Estimator` |
| 15 | `estimator = BackendEstimator(` | Deprecation -> BackendEstimator is deprecated | IK | BackendEstimator | `estimator = Estimator(` |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.opflow import PauliSumOp
from qiskit.primitives import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

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