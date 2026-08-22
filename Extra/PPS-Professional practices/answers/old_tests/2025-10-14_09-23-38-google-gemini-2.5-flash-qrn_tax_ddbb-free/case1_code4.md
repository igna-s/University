| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 11 | `from qiskit import Aer` | Deprecation -> `Aer` module moved to `qiskit_aer` | qrn_tax_ddbb-a74a | qiskit.Aer | `from qiskit_aer import Aer` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | qrn_tax_ddbb-942b | Aer.get_backend | `backend = AerSimulator()` |
| 15 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Deprecation -> `job.result().get_counts(circuit)` is deprecated. | qrn_tax_ddbb-2544 | get_counts(qc) | `job = getJob(qc, backend, 1000).result().get_counts()` |
| 18 | `qc.draw(output='mpl')` | Deprecation -> `output` parameter in `QuantumCircuit.draw()` is deprecated. | qrn_tax_ddbb-d450 | output | `qc.draw(output='mpl', interactive=True)` |


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
job = getJob(qc, backend, 1000).result().get_counts()

import matplotlib.pyplot as plt
qc.draw(output='mpl', interactive=True)
plt.show()
```