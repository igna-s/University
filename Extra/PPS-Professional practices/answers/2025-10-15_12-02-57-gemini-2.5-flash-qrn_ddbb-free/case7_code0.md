| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The module qiskit.test is deprecated | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The module qiskit.test is deprecated | qrn_notax_ddbb--12ee0486-d662-444e-bf93-2dc6e1e66ac2 | qiskit.test | `from qiskit.circuit.library import NLocal` |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> ReferenceCircuits.bell() is deprecated (optional) | IK | ReferenceCircuits.bell() | `qc = NLocal(num_qubits=2, rotation_blocks=['ry', 'rz'], entanglement_blocks='cx', entanglement='linear', reps=1)` |
| 6 | `backend = FakeVigo()` | Deprecation -> FakeVigo class is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | FakeVigo | `backend = FakeVigo()` |


```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import NLocal

qc = NLocal(num_qubits=2, rotation_blocks=['ry', 'rz'], entanglement_blocks='cx', entanglement='linear', reps=1)
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```