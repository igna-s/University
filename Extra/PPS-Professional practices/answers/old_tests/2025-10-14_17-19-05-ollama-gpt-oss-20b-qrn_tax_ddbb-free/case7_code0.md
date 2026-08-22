| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:----:|------|----------|-----------|----------|-------------|
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> qiskit.test.mock module deprecated | IK | qiskit.test.mock | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test.reference_circuits module deprecated | IK | qiskit.test.reference_circuits | Remove import; use manual circuit construction instead |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> ReferenceCircuits.bell() method deprecated | IK | ReferenceCircuits | `qc = QuantumCircuit(2); qc.h(0); qc.cx(0,1)` |

```python
from mylib import getJob, getCount
from qiskit.providers.fake_provider import FakeVigo
from qiskit import QuantumCircuit

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0,1)
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```
