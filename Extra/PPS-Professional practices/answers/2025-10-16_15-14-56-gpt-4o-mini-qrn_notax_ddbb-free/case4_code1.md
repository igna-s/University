| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> The qiskit.tools.events module has been deprecated | qrn_notax_ddbb-75eb347b-938e-47b4-ae4c-f9b885771b04 | qiskit.tools.events | `from tqdm import tqdm` | 
| 10 | `TextProgressBar().update(job)` | Deprecation -> The progressbar() utility has been deprecated | qrn_notax_ddbb-75eb347b-938e-47b4-ae4c-f9b885771b04 | TextProgressBar | `tqdm(job)` |

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob
from tqdm import tqdm

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

tqdm(job)
result = job.result()
counts = result.get_counts()
```