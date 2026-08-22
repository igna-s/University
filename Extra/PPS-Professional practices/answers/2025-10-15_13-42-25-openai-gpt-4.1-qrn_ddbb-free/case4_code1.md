| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | from qiskit.tools.events import TextProgressBar | Deprecation -> The TextProgressBar was removed in Qiskit 1.0.0 | qrn_notax_ddbb--b123f8e3-3bb5-4d84-99d9-d8f89a1cec06 | qiskit.tools.events.TextProgressBar |  |
| 10 | TextProgressBar().update(job) | Removal -> TextProgressBar usage no longer supported | qrn_notax_ddbb--b123f8e3-3bb5-4d84-99d9-d8f89a1cec06 | qiskit.tools.events.TextProgressBar |  |

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