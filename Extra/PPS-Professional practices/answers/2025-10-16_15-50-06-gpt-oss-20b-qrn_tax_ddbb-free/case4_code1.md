| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> qiskit.tools.events.TextProgressBar is deprecated | IK | qiskit.tools.events.TextProgressBar | Remove import |
| 9 | `TextProgressBar().update(job)` | Deprecation -> TextProgressBar().update(job) is deprecated | IK | TextProgressBar | Remove usage |

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