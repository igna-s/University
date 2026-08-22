| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 9 | `from qiskit import Aer` | Deprecation -> Aer module is deprecated | 22 | internal | `qiskit.Aer` | `from qiskit_aer import AerSimulator` |
| 10 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend is deprecated | 22 | internal | `Aer.get_backend` | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Deprecation -> Job.result().get_counts(circuit) is deprecated | 29 | internal | `get_counts(qc)` | `job = getJob(qc, backend, 1000).result().get_counts()` |
| 17 | `qc.draw(output='mpl')` | Deprecation -> circuit.draw(output='mpl') (optional) | 26 | internal | `output='mpl'` | `fig = qc.draw(output='figure')` |


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
fig = qc.draw(output='figure')
plt.show()
```