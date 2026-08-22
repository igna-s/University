| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
|:----:|------|----------|-------------|-----------|----------|-------------|
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> `TextProgressBar` removed in Qiskit 1.0.0 | * | Internal Knowledge | TextProgressBar | Remove import |
| 7 | `TextProgressBar().update(job)` | Deprecation -> `TextProgressBar` removed in Qiskit 1.0.0 | * | Internal Knowledge | TextProgressBar | Replace with `print(f"Job status: {job.status()}")` |

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

print(f"Job status: {job.status()}")
result = job.result()
counts = result.get_counts()
```
