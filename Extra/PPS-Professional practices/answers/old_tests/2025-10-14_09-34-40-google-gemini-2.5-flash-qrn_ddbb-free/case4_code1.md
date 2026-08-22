| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> `qiskit.tools.events.TextProgressBar` has been removed | Internal Knowledge | `qiskit.tools.events.TextProgressBar` | |
| 10 | `TextProgressBar().update(job)` | Deprecation -> `TextProgressBar` functionality has been removed. Progress bar functionality is often integrated into `backend.run()` directly or can be handled by external libraries. | Internal Knowledge | `TextProgressBar().update()` | |


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