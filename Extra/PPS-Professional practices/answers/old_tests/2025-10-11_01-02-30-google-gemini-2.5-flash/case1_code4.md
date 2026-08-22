| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> The `Aer` class in `qiskit.providers.aer` is deprecated, along with the entire `qiskit.providers.aer` namespace. | 13ce828b-b1e7-47b2-ac67-e94589d1ec9c | Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> The `Aer.get_backend()` method is deprecated in Qiskit Aer 0.12 and will be removed in a future release. | 13ce828b-b1e7-47b2-ac67-e94589d1ec9c | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Deprecation -> The parameter `experiment` in `qiskit.result.Result.get_counts()` is deprecated. | 441d6b04-1b33-4085-b91c-79532588e223 | get_counts | `job = getJob(qc, backend, 1000).result().get_counts()` |
| 17 | `qc.draw(output='mpl')` | Deprecation -> `QuantumCircuit.draw()` no longer accepts the `output` parameter to select the drawer backend. | d76c6ae5-1153-4e43-a63e-f9c46ce3f290 | QuantumCircuit.draw | `fig = qc.draw(output='mpl', interactive=True)` |


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
fig = qc.draw(output='mpl', interactive=True)
plt.show()
```