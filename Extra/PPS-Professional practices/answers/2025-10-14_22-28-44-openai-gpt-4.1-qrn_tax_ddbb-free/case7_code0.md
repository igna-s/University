| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit.test.mock import FakeVigo | Deprecation -> FakeVigo removed from qiskit.test.mock | qrn_tax_ddbb-d2316e5828224bf083e34e50f7be7721 | qiskit.test.mock.FakeVigo | from qiskit.providers.fake_provider import FakeVigo |
| 3 | from qiskit.test.reference_circuits import ReferenceCircuits | Deprecation -> ReferenceCircuits removed from qiskit.test.reference_circuits | qrn_tax_ddbb-8406b47e0f014bbf806fff4ec78b8c9a | qiskit.test.reference_circuits.ReferenceCircuits | from qiskit.circuit.library import Bell |

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