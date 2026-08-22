| Line | Code | Scenario | Reference | Artifact | Refactoring | 
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.opflow import PauliSumOp | Deprecation -> The opflow module is deprecated | qrn_tax_ddbb--f7fb03a1-0675-4c52-8cf4-8670e307b690 | qiskit.opflow.PauliSumOp | `from qiskit.quantum_info import SparsePauliOp` |
| 8 | H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]) | Deprecation -> PauliSumOp.from_list() is deprecated | qrn_tax_ddbb--f7fb03a1-0675-4c52-8cf4-8670e307b690 | PauliSumOp.from_list | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |

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