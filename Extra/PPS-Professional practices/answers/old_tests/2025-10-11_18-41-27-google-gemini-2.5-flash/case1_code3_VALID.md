| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
|------|------|----------|-------------|-----------|----------|-------------|
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Import of execute/Aer/qasm is deprecated | * | internal | qiskit imports | `from qiskit import QuantumCircuit` |
| 5 | `from utils import getJob` | Removal -> Unused import removed | * | internal | utils.getJob |  |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Using Aer.get_backend deprecated; use AerSimulator.get_backend | * | internal | Aer.get_backend | `backend = AerSimulator.get_backend('aer_simulator')` |
| 14 | `job = getJob(qc, backend, 1000)` | Deprecation -> Using getJob wrapper deprecated; use backend.run | * | internal | getJob | `job = backend.run(qc, shots=1000)` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from qiskit.providers.aer import Aer as AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator.get_backend('aer_simulator')
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```