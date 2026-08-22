| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 10 | ffd665c6-fea0-4850-aefa-2e7302e527f2 | qiskit.tools.events | |
| 11 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 10 | 509b8eec-1901-4c29-a2c8-04de00f3a847 | TextProgressBar | |


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