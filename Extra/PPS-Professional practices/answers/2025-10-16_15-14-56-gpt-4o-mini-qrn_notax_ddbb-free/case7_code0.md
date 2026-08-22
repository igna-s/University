| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The FakeVigo class is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | qiskit.test.mock | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The ReferenceCircuits module is deprecated | qrn_notax_ddbb--d17f1b3c-e950-46b8-8ca8-e22bfd4cdad0 | qiskit.test.reference_circuits | `from qiskit.circuit.library import ReferenceCircuits` |
| 5 | `job = getJob(qc, backend)` | Deprecation -> The getJob function is deprecated | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | mylib |  |
| 6 | `counts = getCount(job)` | Deprecation -> The getCount function is deprecated | qrn_notax_ddbb--6a782250-d3b0-4afa-a877-8432d57d59aa | mylib |  |

```python  
from qiskit.providers.fake_provider import FakeVigo
from qiskit.circuit.library import ReferenceCircuits

qc = ReferenceCircuits.bell()
backend = FakeVigo()

print("Resultados del circuito Bell:")
print(counts)
```