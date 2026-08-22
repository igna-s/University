| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 12 | `from qiskit import Aer` | Deprecation -> qiskit.Aer object deprecated | f4629adb-1cfe-4469-9df9-d8d0172ab667 | 6 | qiskit.Aer | `from qiskit_aer import Aer` |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() is deprecated | c2c72864-60b6-4a05-8ba8-ea04f14a65c0 | 37 | Aer.get_backend | `backend = AerSimulator()` |
| 20 | `qc.draw(output='mpl')` | Deprecation -> The `output` parameter in `QuantumCircuit.draw()` is deprecated. | a91cddb8-117c-4f41-b0d7-c62c7280f09b | * | QuantumCircuit.draw | `qc.draw('mpl')` |


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
qc.draw('mpl')
plt.show()
```