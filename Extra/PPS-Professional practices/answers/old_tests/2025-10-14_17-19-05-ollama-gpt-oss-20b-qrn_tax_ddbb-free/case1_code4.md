| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 10 | `from qiskit import Aer` | Deprecation -> `Aer` import is deprecated | IK | Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Updated -> Use AerSimulator directly | IK | backend | `backend = AerSimulator()` |

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
