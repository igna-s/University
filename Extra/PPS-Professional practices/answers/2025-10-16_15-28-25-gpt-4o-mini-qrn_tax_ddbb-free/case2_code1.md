| Line | Code                                                                                  | Scenario                                | Reference                             | Artifact            | Refactoring                                          |
| :--: | :----------------------------------------------------------------------------------- | :-------------------------------------- | :------------------------------------ | :------------------ | :-------------------------------------------------- |
| 1    | `from qiskit.circuit.library import RealAmplitudes`                                | Deprecation -> qiskit.circuit.library  | IK                                    | qiskit.circuit      | `from qiskit.circuit.library import RealAmplitudes` |
| 2    | `from qiskit.opflow import PauliSumOp`                                             | Deprecation -> qiskit.opflow            | IK                                    | qiskit.opflow       | `from qiskit.opflow import PauliSumOp`             |
| 3    | `from qiskit.primitives import BackendEstimator`                                    | Deprecation -> qiskit.primitives       | IK                                    | qiskit.primitives    | `from qiskit.primitives import BackendEstimator`    |
| 4    | `from utils import getBackend`                                                      | Structural change -> utils -> qiskit.utils | IK                              | utils               | `from qiskit.utils import getBackend`               |
| 9    | `estimator = BackendEstimator(backend=backend, options={"shots": 1024})`           | Updated -> constructor signature       | IK                                    | BackendEstimator    | `estimator = BackendEstimator(backend=backend, shots=1024)` |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.opflow import PauliSumOp
from qiskit.primitives import BackendEstimator
from qiskit.utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
estimator = BackendEstimator(backend=backend, shots=1024) 

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```