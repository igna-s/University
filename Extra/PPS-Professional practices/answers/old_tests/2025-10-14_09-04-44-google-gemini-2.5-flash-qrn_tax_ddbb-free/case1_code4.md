| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 11 | `from qiskit import Aer` | Deprecation -> `Aer` module moved to `qiskit_aer` | Internal Knowledge | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `get_backend` for `AerSimulator` is replaced by direct instantiation | Internal Knowledge | Aer.get_backend | `backend = AerSimulator()` |
| 17 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Deprecation -> `get_counts` no longer requires `QuantumCircuit` argument | Internal Knowledge | result.get_counts | `job = getJob(qc, backend, 1000).result().get_counts()` |


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
qc.draw(output='mpl')
plt.show()
```