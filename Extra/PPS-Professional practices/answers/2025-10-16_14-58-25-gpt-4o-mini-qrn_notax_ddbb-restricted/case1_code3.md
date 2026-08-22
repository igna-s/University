| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit | `from qiskit import QuantumCircuit, execute, qiskit_aer as Aer` |
| 2 | `backend = Aer.get_backend('aer_simulator')` | Updated -> Aer.get_backend() method | IK | Aer | `backend = Aer.get_backend('aer_simulator')` |
| 7 | `from utils import getJob` | (optional) | IK | utils | `from qiskit_aer import getJob` |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute, qiskit_aer as Aer
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```