| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> Deprecation of qiskit.tools.events module | b34548a9-18c8-4147-aa93-ab0183c684f1 | 12 | qiskit.tools.events | |
| 10 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. | 018bdc08-df40-4266-b4b6-504968ba0f8d | * | TextProgressBar | |


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