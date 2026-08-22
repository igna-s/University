| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The qiskit.opflow module is deprecated | 9f2deafd-17d5-462f-b55d-2fb91b5f4004 | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> The class BackendEstimator is deprecated | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | BackendEstimator | `from qiskit.primitives import Estimator` |
| 13 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | 9f2deafd-17d5-462f-b55d-2fb91b5f4004 | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 17 | `estimator = BackendEstimator(` | Deprecation -> The class BackendEstimator is deprecated | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | BackendEstimator | `estimator = Estimator(` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit.primitives import Estimator
from utils import getBackend

psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

backend = getBackend()
estimator = Estimator(
    backend=backend,
    options={"shots": 1024}
)

job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```