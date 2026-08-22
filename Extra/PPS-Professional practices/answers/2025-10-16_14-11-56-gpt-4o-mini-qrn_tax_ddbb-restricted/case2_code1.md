| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 1 | `from qiskit.circuit.library import RealAmplitudes` | Deprecation -> qiskit.extensions module is deprecated | IK | qiskit.circuit.library | `from qiskit.circuit.library import RealAmplitudes` |  
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> Importing from qiskit.providers.aer is deprecated | IK | qiskit.opflow | `from qiskit.opflow import PauliSumOp` |  
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> Use BackendSampler instead of BackendEstimator | IK | qiskit.primitives | `from qiskit.primitives import BackendSampler` |  
| 4 | `from utils import getBackend` |  |  | utils |  |  
| 5 | `psi1 = RealAmplitudes(num_qubits=2, reps=2)` |  |  |  |  |  
| 6 | `theta1 = [0, 1, 1, 2, 3, 5]` |  |  |  |  |  
| 7 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Use SparsePauliOp instead of PauliSumOp | IK | qiskit.opflow | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |  
| 9 | `backend = getBackend()` |  |  |  |  |  
| 10 | `estimator = BackendEstimator(backend=backend, options={"shots": 1024})` | Replacement -> Use BackendSampler instead of BackendEstimator | IK | qiskit.primitives | `sampler = BackendSampler(backend)` |  
| 13 | `job = estimator.run([psi1], [H1], [theta1])` | Structural change -> Replace estimator.run with sampler.run | IK | qiskit.primitives | `job = sampler.run([psi1], [H1], [theta1])` |  
| 14 | `result = job.result()` |  |  |  |  |  
| 16 | `print(f"Expectation value: {result.values[0]}")` |  |  |  |  |  

```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.opflow import SparsePauliOp
from qiskit.primitives import BackendSampler
from utils import getBackend

psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

backend = getBackend()
sampler = BackendSampler(backend)
job = sampler.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```