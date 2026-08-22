| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.events.TextProgressBar | |
| 11 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | b8601747-ed0a-4488-b998-af8f180f99be | TextProgressBar | |


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