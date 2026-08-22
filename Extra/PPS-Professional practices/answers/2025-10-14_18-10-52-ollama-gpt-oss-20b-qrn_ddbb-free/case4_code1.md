| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> TextProgressBar moved | IK | qiskit.tools.events.TextProgressBar | `from qiskit.tools.qi import TextProgressBar` |

```python
    from qiskit import QuantumCircuit
from utils import createBackendAndrunJob
from qiskit.tools.qi import TextProgressBar

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

TextProgressBar().update(job)
result = job.result()
counts = result.get_counts()
```