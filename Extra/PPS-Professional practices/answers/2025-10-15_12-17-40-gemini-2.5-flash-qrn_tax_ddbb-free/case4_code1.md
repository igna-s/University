| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 4bc2d33a-666a-48ed-96d1-b12d38ea3acf | qiskit.tools.events.TextProgressBar | |
| 10 | `TextProgressBar().update(job)` | Deprecation -> The qiskit.tools.events module and the progressbar() utility it exposed has been deprecated and will be removed in the Qiskit 1.0.0 release. This module’s functionality was not widely used and better covered by dedicated packages such as tqdm. | 4bc2d33a-666a-48ed-96d1-b12d38ea3acf | TextProgressBar().update | |

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