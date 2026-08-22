| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.circuit.library import RealAmplitudes` | Deprecation -> RealAmplitudes is deprecated | qrn_notax_ddbb-f078e9fc-d625-4a36-93e9-4c1f484f9b48 | qiskit.circuit.library | `from qiskit.circuit.library import RealAmplitudes` |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> PauliSumOp is deprecated | qrn_notax_ddbb-9f940bc6-4df3-4cdd-8267-218d027fb253 | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecated -> BackendEstimator | qrn_notax_ddbb-8fa78c41-fe65-4855-a211-6812b683b158 | qiskit.primitives | `from qiskit.primitives import BackendSampler` |
| 8 | `backend = getBackend()` | Deprecated -> getBackend() is removed | qrn_notax_ddbb-2125b2ad-3e2e-494b-b0de-816d0703f19c | utils |  |
| 10 | `job = estimator.run([psi1], [H1], [theta1])` | Update -> Using BackendSampler.run() instead of estimator.run() | qrn_notax_ddbb-6a782250-d3b0-4afa-a877-8432d57d59aa | estimator | `job = sampler.run([psi1], [H1], [theta1])` |
| 12 | `print(f"Expectation value: {result.values[0]}")` | Update -> Accessing value from result needs manual conversion | qrn_notax_ddbb-27c4ca79-960a-4adb-8219-19ecfc9a9e1a | result | `print(f"Expectation value: {result['values'][0]}")` |

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import BackendSampler
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendSampler con backend directamente
backend = getBackend()
sampler = BackendSampler(backend)
job = sampler.run([psi1], [H1], [theta1])

result = job.result()

print(f"Expectation value: {result['values'][0]}")
```