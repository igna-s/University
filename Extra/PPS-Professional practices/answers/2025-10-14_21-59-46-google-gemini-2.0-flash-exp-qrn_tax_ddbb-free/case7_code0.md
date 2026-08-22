| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> The qiskit.test.mock module is deprecated and will be removed in a future release. | qrn_tax_ddbb-119b923d32584729b34561891a44f4a4 | qiskit.test.mock | `from qiskit_ibm_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> The qiskit.test.reference_circuits module is deprecated and will be removed in a future release.  | qrn_tax_ddbb-38326a9fd05547208a5a4549c89c9609 | qiskit.test.reference_circuits | `from qiskit.circuit.library import EfficientSU2` |

```python
from mylib import getJob, getCount
from qiskit_ibm_provider import FakeVigo
from qiskit.circuit.library import EfficientSU2

qc = ReferenceCircuits.bell()
backend = FakeVigo()

job = getJob(qc, backend)
counts = getCount(job)

print("Resultados del circuito Bell:")
print(counts)
```