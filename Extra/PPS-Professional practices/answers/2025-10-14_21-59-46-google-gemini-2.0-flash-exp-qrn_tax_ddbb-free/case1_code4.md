| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 11 | `from qiskit import Aer` | `Deprecated` -> Aer provider is deprecated and slated for removal. | qrn_tax_ddbb-278a899863b342d5b909a9595798460e | `qiskit import Aer` |  `from qiskit_aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | `Deprecated` -> Aer provider is deprecated and slated for removal. | qrn_tax_ddbb-278a899863b342d5b909a9595798460e | `Aer.get_backend` | `backend = AerSimulator()` |
| 16 | `qc.draw(output='mpl')` | `Deprecated` ->  The output kwarg to QuantumCircuit.draw() is deprecated and replaced with the style kwarg as of version 0.19.0. | qrn_tax_ddbb-eff9f2452a654827a95d19c87a7529c2 | `qc.draw` | `qc.draw(style='mpl')` |

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
qc.draw(style='mpl')
plt.show()
```