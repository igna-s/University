| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The `qiskit.tools.events` module is deprecated. | Internal Knowledge | `qiskit.tools.events.TextProgressBar` | |
| 12 | `TextProgressBar().update(job)` | Deprecation -> The `TextProgressBar` class is deprecated and its functionality has been removed. | Internal Knowledge | `TextProgressBar` | |


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