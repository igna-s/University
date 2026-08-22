| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.opflow import PauliSumOp | Deprecation -> qiskit.opflow and PauliSumOp are deprecated | qrn_ddbb-03486903-a26e-456c-97e8-28a854e81152 | qiskit.opflow.PauliSumOp | from qiskit.quantum_info import SparsePauliOp |
| 8 | H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]) | Deprecation -> PauliSumOp.from_list is deprecated | qrn_ddbb-03486903-a26e-456c-97e8-28a854e81152 | PauliSumOp.from_list | H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]) |
| 15 | job = estimator.run([psi1], [H1], [theta1]) | API Change -> Estimator expects observables as SparsePauliOp, not PauliSumOp | qrn_ddbb-03486903-a26e-456c-97e8-28a854e81152 | estimator.run | job = estimator.run([psi1], [H1], [theta1]) |

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
    options={"shots": 1024}
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```