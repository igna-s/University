| Line | Code | Scenario | Reference | Artifact | Refactoring | 
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 9 | `from qiskit import Aer` | Deprecation -> Aer provider is deprecated in favor of qiskit_aer package | qrn_ddbb-4c9abd23d8e04aa6b10f8767b64649fb | qiskit.Aer | `from qiskit_aer import Aer` |
| 10 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() usage is deprecated, use AerSimulator directly | qrn_ddbb-4c9abd23d8e04aa6b10f8767b64649fb | qiskit.Aer.get_backend | `from qiskit_aer import AerSimulator`<br>`backend = AerSimulator()` |

```python  
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import AerSimulator
backend = AerSimulator()

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw(output='mpl')
plt.show()
```