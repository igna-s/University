| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> `qiskit.tools.events` module and the `progressbar()` utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. | 75 | 018bdc08-df40-4266-b4b6-504968ba0f8d | `qiskit.tools.events` | |
| 10 | `TextProgressBar().update(job)` | Deprecation -> `qiskit.tools.events` module and the `progressbar()` utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. | 76 | 018bdc08-df40-4266-b4b6-504968ba0f8d | `TextProgressBar` | |


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