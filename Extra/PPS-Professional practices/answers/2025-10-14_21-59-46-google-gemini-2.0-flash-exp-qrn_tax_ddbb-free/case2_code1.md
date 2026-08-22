| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> opflow module has been replaced by quantum_info and algorithms modules | qrn_tax_ddbb-e9409953ef344251a9f77928a485167d | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 2 | `from qiskit.opflow import PauliSumOp` | Removal -> PauliSumOp class has been removed | qrn_tax_ddbb-894aa96f38894223a82969727c454744 | qiskit.opflow.PauliSumOp |  |
| 9 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Removal -> PauliSumOp class has been removed | qrn_tax_ddbb-894aa96f38894223a82969727c454744 | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |

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
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```