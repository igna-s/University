| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 10 | backend = Aer.get_backend('aer_simulator') | Deprecation -> Aer.get_backend() method deprecated in favor of AerSimulator class | qrn_tax_ddbb-c82bc2be3c5e4bfe99bb8c5d8f77dab5 | qiskit.providers.aer.Aer.get_backend | backend = AerSimulator() |
| 17 | qc.draw(output='mpl') | Change in return value -> qc.draw() returns PIL.Image, not matplotlib.Figure | qrn_tax_ddbb-b017a3dcfdf74d139323de01ef0931a1 | QuantumCircuit.draw | img = qc.draw(output='mpl'); plt.imshow(img); plt.axis('off') |

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
img = qc.draw(output='mpl')
plt.imshow(img)
plt.axis('off')
plt.show()
```