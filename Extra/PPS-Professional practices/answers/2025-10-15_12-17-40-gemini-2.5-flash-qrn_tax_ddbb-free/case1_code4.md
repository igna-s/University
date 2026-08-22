| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 13 | `from qiskit import Aer` | Deprecation -> The qiskit.Aer object is deprecated | 4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit.Aer | `from qiskit_aer import Aer` |
| 18 | `qc.draw(output='mpl')` | Deprecation -> `QuantumCircuit.draw()` output parameter | IK | QuantumCircuit.draw | `qc.draw(output='mpl', interactive=False)` |


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
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw(output='mpl', interactive=False)
plt.show()
```