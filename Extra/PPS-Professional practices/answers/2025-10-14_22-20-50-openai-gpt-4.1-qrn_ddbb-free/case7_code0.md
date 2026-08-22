| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.test.mock import FakeVigo | Deprecation -> FakeVigo removed in 1.0.0 | qrn_ddbb-c2f6c4c4acb4406e9a20d7d5d1cb40b6 | qiskit.test.mock.FakeVigo | from qiskit.providers.fake_provider import FakeVigo |
| 3 | from qiskit.test.reference_circuits import ReferenceCircuits | Deprecation -> ReferenceCircuits removed in 1.0.0 | qrn_ddbb-20286077e12c4f49acbe5b7d2b16010b | qiskit.test.reference_circuits.ReferenceCircuits | from qiskit.circuit.library import Bell |

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