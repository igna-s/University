| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 8f039439-6b74-4203-9559-e21f717e31c3 | qiskit.tools.events | |
| 11 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 8f039439-6b74-4203-9559-e21f717e31c3 | TextProgressBar | |


```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

# TextProgressBar().update(job) - Deprecated, consider using tqdm for progress bar
result = job.result()
counts = result.get_counts()
```