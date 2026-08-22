| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import qasm` | Removal -> The `qasm` module is removed from qiskit | IK | qiskit.qasm |  |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Changed -> Module Aer has been moved | IK | Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Changed -> Module Aer has been moved | IK | Aer | `backend = AerSimulator()` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
import matplotlib.pyplot as plt
from utils import getJob
from qiskit_aer import AerSimulator

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