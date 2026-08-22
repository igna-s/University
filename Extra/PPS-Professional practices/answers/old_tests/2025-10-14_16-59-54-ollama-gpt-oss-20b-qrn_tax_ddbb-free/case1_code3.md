| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The import of Aer and qasm is deprecated in Qiskit 1.0.0 | IK | qiskit import | `from qiskit import QuantumCircuit, execute`<br>`from qiskit_aer import AerSimulator` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Migration -> The Aer backend provider has been removed; use AerSimulator | IK | Aer.get_backend | `backend = AerSimulator()` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit_aer import AerSimulator
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
