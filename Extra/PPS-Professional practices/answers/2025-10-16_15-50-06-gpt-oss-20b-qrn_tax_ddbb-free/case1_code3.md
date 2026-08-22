| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `qasm` import removed | IK | qasm | Remove `qasm` from import |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Updated -> `Aer.get_backend` replaced by `AerSimulator()` | IK | Aer | Change to `backend = AerSimulator()` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit.providers.aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```