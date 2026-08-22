| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> qiskit.test module is deprecated | 12 | 5499d167-51d1-4e3f-bac2-58f69b9e9f89 | qiskit.test | |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test module is deprecated | 12 | 5499d167-51d1-4e3f-bac2-58f69b9e9f89 | qiskit.test | |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> qiskit.test module is deprecated | 12 | 5499d167-51d1-4e3f-bac2-58f69b9e9f89 | qiskit.test.reference_circuits.ReferenceCircuits | |
| 6 | `backend = FakeVigo()` | Structural change -> FakeProvider and fake backends moved to `qiskit_ibm_runtime.fake_provider` | 38 | 6173c30d-f69e-41c5-87eb-9c391a8e307b | FakeVigo | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |


```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import BellState

qc = BellState()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```