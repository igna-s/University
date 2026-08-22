| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> qiskit.test.mock module removed, import path changed | IK | qiskit.test.mock | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test.reference_circuits module removed, import path changed | IK | qiskit.test.reference_circuits | `from qiskit.circuit.library import ReferenceCircuits` |

```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import ReferenceCircuits

qc = ReferenceCircuits.bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```
