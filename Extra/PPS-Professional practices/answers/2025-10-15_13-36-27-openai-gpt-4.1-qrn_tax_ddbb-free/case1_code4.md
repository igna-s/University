| Line | Code | Scenario | Reference | Artifact | Refactoring | 
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 9 | `from qiskit import Aer` | Deprecation -> The Aer provider is now in qiskit_aer | qrn_tax_ddbb--aae8c9a9-1e12-4493-9349-6dcf67ec901f | qiskit.Aer | `from qiskit_aer import Aer` | 
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> get_backend is not recommended, use AerSimulator | qrn_tax_ddbb--de124ad3-44b6-4cbf-81a9-3f77310ea8d6 | qiskit.Aer.get_backend | `backend = AerSimulator()` | 
| 20 | `qc.draw(output='mpl')` | API Change -> draw does not return pyplot figure by default; use as reference to integrate with matplotlib | qrn_tax_ddbb--149aed3d-9e5d-4d06-b1dd-f1063481a26c | QuantumCircuit.draw | `fig = qc.draw('mpl')` |
| 21 | `plt.show()` | API Change (optional) -> plt.show() needs returned figure from draw | IK | matplotlib.pyplot.show | `plt.show()` |

```python
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
from qiskit_aer import AerSimulator
backend = AerSimulator()

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
fig = qc.draw('mpl')
plt.show()
```