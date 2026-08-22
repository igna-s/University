| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> qiskit.test.mock import is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.test.mock.FakeVigo | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> qiskit.test.reference_circuits is deprecated | qrn_notax_ddbb--53437692-c254-4ce5-9d8a-b21eda6ad0fc | qiskit.test.reference_circuits | `from qiskit.circuit.library import BellCircuit` |
| 5 | `qc = ReferenceCircuits.bell()` | Deprecation -> ReferenceCircuits.bell() is deprecated | qrn_notax_ddbb--53437692-c254-4ce5-9d8a-b21eda6ad0fc | ReferenceCircuits.bell | `qc = BellCircuit().to_circuit()` |

```python
from mylib import getJob, getCount
from qiskit_ibm_runtime.fake_provider import FakeVigo
from qiskit.circuit.library import BellCircuit

qc = BellCircuit().to_circuit()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```
