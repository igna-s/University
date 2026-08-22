| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> Implicit conversion from a dense BaseOperator to a SparsePauliOp in Estimator observable arguments is deprecated as of Qiskit 0.46 and will be removed in Qiskit 1.0. You should explicitly convert to a SparsePauliOp using SparsePauliOp.from_operator() instead. | f8f5e7ed-990e-4a31-9035-2032af8be117 | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | 084696d9-2c75-437a-8e84-96506e6766aa | qiskit.primitives | `from qiskit_aer.primitives import Estimator` |
| 11 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | 039bc9ef-72bf-4376-9047-3e418906d0e0 | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 14 | `estimator = BackendEstimator(` | Deprecation -> The qiskit.providers.basicaer module and all of its classes are deprecated from Qiskit 0.46 onwards. Their use should be replaced with the qiskit.quantum_info module and the new qiskit.providers.basic_provider module. | 5675e75e-e976-4a4d-a2c7-23dc577eab7d | BackendEstimator | `estimator = Estimator(` |


```python
from qiskit.circuit.library import RealAmplitudes
from qiskit.quantum_info import SparsePauliOp
from qiskit_aer.primitives import Estimator
from utils import getBackend

# 1. Crear circuito parametrizado
psi1 = RealAmplitudes(num_qubits=2, reps=2)
theta1 = [0, 1, 1, 2, 3, 5]

# 2. Crear operador Pauli
H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])

# 3. Configurar BackendEstimator con backend directamente
backend = getBackend()
estimator = Estimator(
    backend=backend,
    options={"shots": 1024}  # Configurar shots aquí
)

# 4. Ejecutar cálculo
job = estimator.run([psi1], [H1], [theta1])
result = job.result()

print(f"Expectation value: {result.values[0]}")
```