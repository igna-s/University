| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 5 | `from qiskit import QuantumCircuit` | Import is now part of the main qiskit namespace. | 10 | 3a8e3d3b-7f5e-4e4d-8f7a-9f1e0b8c7d6a | qiskit | `from qiskit.circuit import QuantumCircuit` |
| 9 | `from qiskit import Aer` | `Aer` is deprecated. | 2 | 7b2c4f0e-4a1d-4c1e-8e8d-6c3a1b9e0d2f | Aer | `from qiskit_aer import AerSimulator` |
| 10 | `backend = Aer.get_backend('aer_simulator')` | `Aer.get_backend` is deprecated. | 2 | 7b2c4f0e-4a1d-4c1e-8e8d-6c3a1b9e0d2f | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | `result().get_counts()` has been deprecated. Use `result.get_counts()` instead. | 17 | 4c9e2b1d-3f8a-4e1c-8f7d-2b1c0e9a8d7f | result().get_counts | `job = getJob(qc, backend, 1000).result().get_counts()` |
| 17 | `qc.draw(output='mpl')` | `mpl` output is deprecated. Use `matplotlib` instead. | 13 | 9d1c8a7b-4e2d-4c1f-8f0e-3b2a1c0d9e8f | qc.draw | `qc.draw(output='matplotlib')` |

```python
import os

from qiskit.circuit import QuantumCircuit
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
qc.draw(output='matplotlib')
plt.show()
```