| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> execute() and qasm() functions deprecated (optional) | IK | qiskit | `from qiskit import QuantumCircuit` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Updated -> BasicProvider replacing Aer (mandatory) | qrn_ddbb-6900711d-c5ca-4455-bd05-66925203dbaf | Aer | `backend = BasicSimulator()` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from utils import getJob
from qiskit.providers.basic_provider import BasicSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = BasicSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```
