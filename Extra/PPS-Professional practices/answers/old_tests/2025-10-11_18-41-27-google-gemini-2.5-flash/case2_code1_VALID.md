| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> BackendEstimator is deprecated | * | internal | BackendEstimator | `from qiskit.primitives.estimator import Estimator` |
| 15 | `estimator = BackendEstimator(` | Deprecation -> BackendEstimator constructor is deprecated | * | internal | BackendEstimator | `estimator = Estimator(` |
| 17 | `options={"shots": 1024}  # Configurar shots aquí` | Deprecation -> options parameter removed; use shots | * | internal | options | `shots=1024` |
| 18 | `)` | No change | * | internal | None | `)` |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.opflow import PauliSumOp
from qiskit.primitives.estimator import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar Estimator con backend directamente
backend = getBackend()
estimator = Estimator(
    backend=backend,
    shots=1024
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```