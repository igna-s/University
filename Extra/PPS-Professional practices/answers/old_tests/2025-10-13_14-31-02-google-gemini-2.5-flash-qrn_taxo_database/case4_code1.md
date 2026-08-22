| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 10 | 7bc0146e-0c67-4a09-ac91-4e96adaf69a6 | qiskit.tools.events | |
| 11 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 10 | 23f333ac-65e6-4eb4-939e-e3253409b471 | TextProgressBar | |


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