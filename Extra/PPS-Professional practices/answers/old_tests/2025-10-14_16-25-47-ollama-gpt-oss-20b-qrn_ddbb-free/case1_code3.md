| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Import of Aer is deprecated (optional) | IK | qiskit | `from qiskit import QuantumCircuit, execute`<br>`from qiskit.providers.aer import AerSimulator` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() is deprecated | IK | Aer | `backend = AerSimulator()` |

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
