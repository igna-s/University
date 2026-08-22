| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `execute` and `qasm` functions are deprecated | IK | execute, qasm | `from qiskit import QuantumCircuit, Aer` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Updated -> Use `AerSimulator` class | IK | Aer | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000)` | Deprecation -> replace `getJob` with `backend.run()` | IK | getJob | `job = backend.run(qc, shots=1000)` |
| 15 | `result = job.result().get_counts(qc)` | Optional -> still valid | IK | job | (none) |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, Aer
from qiskit.providers.aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = backend.run(qc, shots=1000)
result = job.result()
counts = result.get_counts(qc)
plt.show()
```
