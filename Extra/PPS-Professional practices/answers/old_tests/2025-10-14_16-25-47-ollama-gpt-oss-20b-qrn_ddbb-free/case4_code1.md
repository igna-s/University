| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|------------|
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> TextProgressBar removed in 1.0 | IK | qiskit.tools.events | `from qiskit.providers.jobmonitor import JobMonitor` |
| 8 | `TextProgressBar().update(job)` | Removal -> ProgressBar replaced by JobMonitor or omitted | IK | qiskit.providers.jobmonitor |  |

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob
from qiskit.providers.jobmonitor import JobMonitor

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

job_monitor = JobMonitor(job)
job_monitor.wait()

result = job.result()
counts = result.get_counts()
```