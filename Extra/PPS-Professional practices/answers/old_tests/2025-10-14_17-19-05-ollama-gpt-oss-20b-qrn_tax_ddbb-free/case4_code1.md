```markdown
| Line | Code                                 | Scenario                                           | Reference | Artifact                        | Refactoring                              |
|:----:|--------------------------------------|----------------------------------------------------|-----------|----------------------------------|-------------------------------------------|
| 3    | `from qiskit.tools.events import TextProgressBar` | Deprecation -> qiskit.tools.events module is deprecated | IK        | qiskit.tools.events.TextProgressBar | `# remove import (module removed in Qiskit 1.0)` |
| 12   | `TextProgressBar().update(job)`       | Deprecation -> TextProgressBar.update() is deprecated | IK        | TextProgressBar                  | `# remove usage (progress bar removed in Qiskit 1.0)` |
```

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
