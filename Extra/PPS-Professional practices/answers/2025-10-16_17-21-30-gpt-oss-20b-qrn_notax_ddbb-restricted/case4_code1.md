| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> qiskit.tools.events module deprecated, will be removed in Qiskit 1.0.0 | qrn_notax_ddbb-b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.events.TextProgressBar | Remove import of TextProgressBar |
| 12 | `TextProgressBar().update(job)` | Deprecation -> qiskit.tools.events module deprecated, will be removed in Qiskit 1.0.0 | qrn_notax_ddbb-b8601747-ed0a-4488-b998-af8f180f99be | TextProgressBar.update | Remove TextProgressBar update call |

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

result = job.result()
counts = result.get_counts()
```