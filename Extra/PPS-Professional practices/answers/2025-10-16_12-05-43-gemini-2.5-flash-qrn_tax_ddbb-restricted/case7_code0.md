| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The module qiskit.test is deprecated | d9f84579-d58f-43da-a4e4-2a4e04dd79cd | qiskit.test.mock | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The module qiskit.test is deprecated | d9f84579-d58f-43da-a4e4-2a4e04dd79cd | qiskit.test.reference_circuits | `from qiskit.circuit.library import (QuantumVolume, QFT, RealAmplitudes, EfficientSU2, NLocal, TwoLocal, PauliEvolution, ExcitationPreserving, IQP, GraphState, Permutation, QPE, RYRZ, ZZFeatureMap, ZFeatureMap, FourierFeatureMap, Birch, VQE, QSVT, Grover, PhaseEstimation, QAOA, EvolvedOperatorAnsatz, HamiltonianEvolution, UniformRotation, PiecewisePolynomial, ExactEvolution, Gate, MCMT, WeightedAdder, LinearAmplitudeFunction, DiagonalGate, HamiltonianGateGate, Initialize, Isometry, MCGupDiag, UCGate, UCPauliRotGate, UCRXGate, UCRYGate, UCRZGate, UnitaryGate)` |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> Most objects have been moved to qiskit.circuit.library, including: DiagonalGate, HamiltonianGateGate, Initialize, Isometry, MCGupDiag, UCGate, UCPauliRotGate, UCRXGate, UCRYGate, UCRZGate, UnitaryGate. | 0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | ReferenceCircuits.bell | `qc = QuantumVolume(1).decompose().decompose()` |
| 6 | `backend = FakeVigo()` | Deprecation -> FakeVigo is deprecated. It has been superseded by the new GenericBackendV2 class. | 27ebf47d-f549-4a4b-ad7c-72ec480eb99d | FakeVigo | `backend = GenericBackendV2(num_qubits=5)` |
| 8 | `job = getJob(qc, backend)` | (optional) -> Using a PauliList as an observable that is implicitly converted to a SparsePauliOp with coefficients 1 when calling Estimator.run() is deprecated. Instead you should explicitly convert the argument using SparsePauliOp(pauli_list) first. | 039bc9ef-72bf-4376-9047-3e418906d0e0 | job | `job = backend.run(qc)` |


```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import (QuantumVolume, QFT, RealAmplitudes, EfficientSU2, NLocal, TwoLocal, PauliEvolution, ExcitationPreserving, IQP, GraphState, Permutation, QPE, RYRZ, ZZFeatureMap, ZFeatureMap, FourierFeatureMap, Birch, VQE, QSVT, Grover, PhaseEstimation, QAOA, EvolvedOperatorAnsatz, HamiltonianEvolution, UniformRotation, PiecewisePolynomial, ExactEvolution, Gate, MCMT, WeightedAdder, LinearAmplitudeFunction, DiagonalGate, HamiltonianGateGate, Initialize, Isometry, MCGupDiag, UCGate, UCPauliRotGate, UCRXGate, UCRYGate, UCRZGate, UnitaryGate)

qc = QuantumVolume(1).decompose().decompose()
backend = FakeVigo()

job = backend.run(qc)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```