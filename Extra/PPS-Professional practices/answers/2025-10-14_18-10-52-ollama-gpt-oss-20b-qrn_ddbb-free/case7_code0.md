| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> `qiskit.test.mock` module is deprecated; `FakeVigo` moved to `qiskit.providers.fake_provider` | b2a36172-1679-422a-ace5-1dac4494834e | FakeVigo | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> `qiskit.test.reference_circuits` removed in 1.0.0 | IK | ReferenceCircuits | Replace import with manual circuit creation using `QuantumCircuit` |
| 4 | `qc = ReferenceCircuits.bell()` | Deprecation -> reference circuit removed | IK | ReferenceCircuits | `qc = QuantumCircuit(2); qc.h(0); qc.cx(0, 1)` |
| 5 | `backend = FakeVigo()` | No change needed after import update | IK | FakeVigo |  |

```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit.circuit import QuantumCircuit

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)

backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```
