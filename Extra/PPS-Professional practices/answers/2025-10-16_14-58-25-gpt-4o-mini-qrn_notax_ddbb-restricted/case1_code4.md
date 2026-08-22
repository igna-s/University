| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 5 | `from qiskit import Aer` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | qiskit | `from qiskit_aer import Aer` |
| 7 | `backend = Aer.get_backend('aer_simulator')` | Updated -> Use of Aer.get_backend() | IK | Aer | `backend = Aer.get_backend('aer_simulator')` |
| 9 | `from utils import getJob` | (optional) | IK | utils |  |
| 13 | `qc.draw(output='mpl')` | Updated -> QuantumCircuit.qasm() method is deprecated | IK | QuantumCircuit | `qc.draw('mpl')` |

```python
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
backend = Aer.get_backend('aer_simulator')

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw('mpl')
plt.show()
```