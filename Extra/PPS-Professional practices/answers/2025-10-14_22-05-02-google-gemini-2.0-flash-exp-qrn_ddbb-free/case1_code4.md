| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> Aer provider is deprecated | qrn_ddbb-3e1d4f1a4a11a35d1007a08ca8408e12 | Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Replacement ->  backend.get_backend is replaced | qrn_ddbb-9458456230d47b98934723ef9781498c | Aer.get_backend | `backend = AerSimulator()` |
| 13 | `from utils import getJob` | Removal -> The function/module utils is removed | IK | utils |  |

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

from datetime import datetime
job = backend.run(qc, shots=1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw(output='mpl')
plt.show()
```