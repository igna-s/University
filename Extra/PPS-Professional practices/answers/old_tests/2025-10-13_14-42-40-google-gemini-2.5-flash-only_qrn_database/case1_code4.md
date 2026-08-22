| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> Importing from `qiskit.Aer` is deprecated. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | * | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer.get_backend | `backend = AerSimulator()` |
| 15 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | API Change (optional) -> `result().get_counts()` no longer requires the circuit argument. | * | Internal Knowledge | get_counts(qc) | `job = getJob(qc, backend, 1000).result().get_counts()` |


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