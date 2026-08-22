| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> FakeVigo moved to `qiskit.providers.fake_provider` | IK | FakeVigo | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> ReferenceCircuits removed; use `Bell` from `qiskit.circuit.library` | IK | ReferenceCircuits | `from qiskit.circuit.library import Bell` |
| 4 | `qc = ReferenceCircuits.bell()` | Deprecation -> ReferenceCircuits.bell() removed; use `Bell()` | IK | Bell | `qc = Bell()` |

```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit.circuit.library import Bell

qc = Bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```