| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.tools.events import TextProgressBar | Removal -> TextProgressBar has been removed in Qiskit 1.0 | qrn_tax_ddbb--b2af8e52-353a-42c0-bd16-75bc95c0f322 | qiskit.tools.events.TextProgressBar |  |
| 10 | TextProgressBar().update(job) | Removal -> TextProgressBar has been removed in Qiskit 1.0 | qrn_tax_ddbb--b2af8e52-353a-42c0-bd16-75bc95c0f322 | qiskit.tools.events.TextProgressBar |  |

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