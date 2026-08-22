| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.tools.events import TextProgressBar | Deprecation -> qiskit.tools.events will be removed in Qiskit 1.0.0 | qrn_ddbb-8d981a2b-adbb-4650-9a61-dcee319ce4ab | qiskit.tools.events.TextProgressBar | Remove this import and use a dedicated progress bar package like tqdm or omit progress bar functionality |
| 10 | TextProgressBar().update(job) | Deprecation -> qiskit.tools.events and related progress bar utilities removed | qrn_ddbb-8d981a2b-adbb-4650-9a61-dcee319ce4ab | qiskit.tools.events.TextProgressBar | Remove this line or replace with a custom/job status print statement |

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