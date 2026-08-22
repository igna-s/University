| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> `TextProgressBar` from qiskit.tools.events is deprecated | IK | TextProgressBar | Remove import |
| 12 | `TextProgressBar().update(job)` | Deprecation -> usage of `TextProgressBar` is deprecated (optional) | IK | TextProgressBar | Remove line |

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
