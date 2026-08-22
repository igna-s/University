| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> `Aer` module moved to `qiskit_aer` | * | internal | `qiskit.Aer` | `from qiskit_aer import Aer` |
| 15 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Deprecation -> `get_counts()` no longer accepts `QuantumCircuit` object as argument | * | internal | `result.get_counts` | `job = getJob(qc, backend, 1000).result().get_counts()` |


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
job = getJob(qc, backend, 1000).result().get_counts()

import matplotlib.pyplot as plt
qc.draw(output='mpl')
plt.show()
```