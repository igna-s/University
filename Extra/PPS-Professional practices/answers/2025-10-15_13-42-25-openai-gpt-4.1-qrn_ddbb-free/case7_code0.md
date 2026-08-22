| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | from qiskit.test.mock import FakeVigo | Deprecation -> The FakeVigo backend moved from qiskit.test.mock to qiskit.providers.fake_provider | qrn_notax_ddbb--96b6d043-39cb-4f7c-9edd-7ba93e73ed67 | FakeVigo | from qiskit.providers.fake_provider import FakeVigo |


```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit.test.reference_circuits import ReferenceCircuits

qc = ReferenceCircuits.bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```