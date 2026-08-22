**Changes required for Qiskit 1.0.0**

| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|--------------|
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation → `execute()` function is deprecated | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `from qiskit import QuantumCircuit` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation → Importing from `qiskit.providers.aer` is deprecated and will stop working in Qiskit 1.0 | 548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend | `from qiskit_aer import AerSimulator; backend = AerSimulator()` |

**Refactored code for Qiskit 1.0.0**

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator; backend = AerSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```
