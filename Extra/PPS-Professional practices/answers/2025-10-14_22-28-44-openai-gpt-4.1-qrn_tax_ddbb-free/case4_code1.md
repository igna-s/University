| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |

| 3 | from qiskit.tools.events import TextProgressBar | Deprecation -> The qiskit.tools.events module and the progressbar() utility will be removed in Qiskit 1.0.0 (replace with external progress bar or remove) | qrn_tax_ddbb-55d90aa5-cb5e-4195-9423-24996e3d9943 | qiskit.tools.events.TextProgressBar |  |
| 10 | TextProgressBar().update(job) | Deprecation -> The qiskit.tools.events module and the progressbar() utility will be removed in Qiskit 1.0.0 (replace with external progress bar or remove) | qrn_tax_ddbb-55d90aa5-cb5e-4195-9423-24996e3d9943 | qiskit.tools.events.TextProgressBar |  |

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