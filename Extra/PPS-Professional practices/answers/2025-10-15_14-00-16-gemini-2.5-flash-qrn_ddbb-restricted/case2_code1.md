| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> Implicit conversion from a dense BaseOperator` to a SparsePauliOp in Estimator observable arguments is deprecated as of Qiskit 0.46 and will be removed in Qiskit 1.0. | 6a782250-d3b0-4afa-a877-8432d57d59aa | PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 10 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | 2125b2ad-3e2e-494b-b0de-816d0703f19c | PauliSumOp.from_list | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |


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