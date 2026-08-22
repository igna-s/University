| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> qiskit.test.mock module is deprecated | d9f84579-d58f-43da-a4e4-2a4e04dd79cd | qiskit.test.mock | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test.reference_circuits module is deprecated | d9f84579-d58f-43da-a4e4-2a4e04dd79cd | qiskit.test.reference_circuits | `from qiskit.circuit.library import BellState` |
| 5 | `qc = ReferenceCircuits.bell()` | Update -> replace with BellState circuit | IK | ReferenceCircuits | `qc = BellState()` |

```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit.circuit.library import BellState

qc = BellState()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```