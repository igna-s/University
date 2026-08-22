| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The module `qiskit.test` is deprecated and will be removed in Qiskit 1.0.0. Use `qiskit_ibm_runtime.fake_provider` instead. | 77 | ffefd8a9-6b59-421f-82e6-98595536086e | qiskit.test.mock | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The module `qiskit.test` is deprecated and will be removed in Qiskit 1.0.0. | 77 | ffefd8a9-6b59-421f-82e6-98595536086e | qiskit.test.reference_circuits | `from qiskit.circuit.library import BellState` |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated. Use `QuantumCircuit.bell()` or `BellState()` from `qiskit.circuit.library` instead. | * | internal | ReferenceCircuits.bell() | `from qiskit.circuit.library import BellState; qc = BellState()` |
| 6 | `backend = FakeVigo()` | Deprecation -> `FakeVigo` is deprecated. Use `GenericBackendV2(num_qubits=5)` from `qiskit_ibm_runtime.fake_provider` instead. | 149 | 96533960-c282-41c1-86d8-f9bc7fa809d8 | FakeVigo | `backend = GenericBackendV2(num_qubits=5)` |


```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import BellState
from qiskit_ibm_runtime.fake_provider import GenericBackendV2

qc = BellState()
backend = GenericBackendV2(num_qubits=5)

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```