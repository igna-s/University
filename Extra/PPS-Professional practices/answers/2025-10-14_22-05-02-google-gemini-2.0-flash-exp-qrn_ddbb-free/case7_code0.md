| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The qiskit.test.mock module is deprecated | qrn_ddbb-45a3e25c126a46a58304a99170068d39 | qiskit.test.mock | `from qiskit_ibm_provider.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The qiskit.test.reference_circuits module is deprecated | qrn_ddbb-1ca776a0c926481c829d224980c4ff26 | qiskit.test.reference_circuits | `from qiskit.circuit.library import standard_gates as gates` |

```python
from mylib import getJob, getCount
from qiskit_ibm_provider.fake_provider import FakeVigo
from qiskit.circuit.library import standard_gates as gates

qc = gates.Bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```