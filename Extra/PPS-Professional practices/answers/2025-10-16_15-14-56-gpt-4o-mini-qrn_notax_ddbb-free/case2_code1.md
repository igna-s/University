| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit.circuit.library import RealAmplitudes` | Deprecation -> Importing from qiskit.circuit.library is deprecated | IK | qiskit.circuit.library | `from qiskit.circuit import RealAmplitudes` |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> Importing from qiskit.opflow is deprecated | IK | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> BackendEstimator has changed | IK | qiskit.primitives | `from qiskit.primitives import Sampler` |
| 4 | `from utils import getBackend` | (optional) No modification needed | IK | utils |  |
| 7 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecated -> Using PauliList as an observable is deprecated | IK | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 9 | `estimator = BackendEstimator(backend=backend, options={"shots": 1024})` | Refactor -> The BackendEstimator function is deprecated | IK | BackendEstimator | `sampler = BackendSampler(backend)` |
| 11 | `job = estimator.run([psi1], [H1], [theta1])` | Refactor -> The run method is modified after BackendEstimator deprecation | IK | estimator | `job = sampler.run(psi1, H1, theta1)` |
| 12 | `result = job.result()` | (optional) No modification needed | IK | job |  |
| 14 | `print(f"Expectation value: {result.values[0]}")` | (optional) No modification needed | IK | result |  |

```python
from qiskit.circuit import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Sampler
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
sampler = Sampler(backend)
        
# 4. Ejecutar cálculo
job = sampler.run(psi1, H1, theta1)
result = job.result()

print(f"Expectation value: {result.values[0]}")
```