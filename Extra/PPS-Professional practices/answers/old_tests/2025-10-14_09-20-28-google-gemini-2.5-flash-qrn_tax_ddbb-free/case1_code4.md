| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 11 | `from qiskit import Aer` | Deprecation -> The `qiskit.Aer` module for backend retrieval is deprecated. | Internal Knowledge | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> The `Aer.get_backend()` method is deprecated; use the `AerSimulator` class directly. | Internal Knowledge | Aer.get_backend | `backend = AerSimulator()` |


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