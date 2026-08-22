| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 13 | `from qiskit import Aer` | Deprecation -> qiskit.Aer object is deprecated | f4629adb-1cfe-4469-9df9-d8d0172ab667 | 6 | qiskit.Aer | `from qiskit_aer import Aer` |
| 14 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> qiskit.providers.aer is deprecated | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | 7 | Aer.get_backend | `backend = AerSimulator()` |


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