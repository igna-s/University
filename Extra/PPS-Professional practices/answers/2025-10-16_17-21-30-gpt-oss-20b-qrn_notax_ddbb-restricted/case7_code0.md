| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> FakeVigo import is deprecated |  | FakeVigo | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> ReferenceCircuits import is deprecated |  | ReferenceCircuits | `from qiskit.circuit.library import Bell` |
| 5 | `qc = ReferenceCircuits.bell()` | Migration -> ReferenceCircuits.bell() replaced by Bell() |  | ReferenceCircuits.bell() | `qc = Bell()` |
| 6 | `backend = FakeVigo()` | No functional change; updated import already applied |  | FakeVigo |  |

```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import Bell

qc = Bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```
