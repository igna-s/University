| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The `qiskit.tools` module is deprecated. | Internal Knowledge | `TextProgressBar` | |
| 11 | `TextProgressBar().update(job)` | Deprecation -> `TextProgressBar` class and its `update` method are deprecated. | Internal Knowledge | `TextProgressBar().update()` | |


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