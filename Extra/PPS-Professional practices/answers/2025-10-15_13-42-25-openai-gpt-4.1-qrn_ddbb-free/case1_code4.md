| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 7 | `from qiskit import Aer` | Deprecation -> The Aer provider is deprecated and will be removed in a future release | qrn_notax_ddbb--0dcb9f15-697b-4c19-8620-aa2da3a4b888 | qiskit.Aer | `from qiskit.providers.aer import Aer` | 
| 8 | `backend = Aer.get_backend('aer_simulator')` | Change Required -> Use AerSimulator instead of Aer.get_backend('aer_simulator') | qrn_notax_ddbb--6351aeef-4b1c-435d-9bfb-be53aec02cda | Aer.get_backend | `from qiskit.providers.aer import AerSimulator`<br>`backend = AerSimulator()` |
| 15 | `qc.draw(output='mpl')` | API Change -> output keyword argument is replaced with 'style' in QuantumCircuit.draw | qrn_notax_ddbb--e4c62e41-9092-4b99-8a41-ca3b1e4a4fae | QuantumCircuit.draw | `qc.draw(style='mpl')` | 

```python
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit.providers.aer import AerSimulator
backend = AerSimulator()

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw(style='mpl')
plt.show()
```