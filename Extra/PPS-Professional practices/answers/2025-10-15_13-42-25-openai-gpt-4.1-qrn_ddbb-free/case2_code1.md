| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.opflow import PauliSumOp | Deprecation -> PauliSumOp has been deprecated in favor of qiskit.quantum_info.SparsePauliOp | qrn_notax_ddbb--e2fe3d54-446a-4497-9390-6ccf283258aa | qiskit.opflow.PauliSumOp | from qiskit.quantum_info import SparsePauliOp |
| 7 | H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]) | Removal -> PauliSumOp.from_list() replaced by SparsePauliOp.from_list() | qrn_notax_ddbb--3eadae94-ab67-4bd1-80f7-5e3cb8f8325f | PauliSumOp.from_list | H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)]) |

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