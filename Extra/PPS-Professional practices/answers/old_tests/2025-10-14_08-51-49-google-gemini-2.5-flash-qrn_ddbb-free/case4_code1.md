| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> `TextProgressBar` has been removed | Internal Knowledge | `TextProgressBar` | |
| 10 | `TextProgressBar().update(job)` | Deprecation -> `TextProgressBar` has been removed | Internal Knowledge | `TextProgressBar` | |


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