| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |   
| 3 | `from qiskit.tools.events import TextProgressBar` | Deprecation -> qiskit.tools.events.TextProgressBar is deprecated | * | internal | qiskit.tools.events.TextProgressBar | `from qiskit.providers import ProgressBar` |   
| 12 | `TextProgressBar().update(job)` | Deprecation -> TextProgressBar().update() usage replaced | * | internal | TextProgressBar | `ProgressBar().update(job)` |   

```python
from qiskit import QuantumCircuit
from utils import createBackendAndrunJob
from qiskit.providers import ProgressBar

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

job = createBackendAndrunJob()

ProgressBar().update(job)
result = job.result()
counts = result.get_counts()
```
