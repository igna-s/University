| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 12 | `from qiskit import Aer` | Deprecation -> `Aer` module has been moved to `qiskit_aer` | 15 | 9675662f-0428-4b77-a859-994119d533ea | Aer | `from qiskit_aer import Aer` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend` method has been removed, use `AerSimulator()` constructor directly. | 16 | 0a2491b4-7935-46aa-836e-d06484e03022 | get_backend | `backend = AerSimulator()` |


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