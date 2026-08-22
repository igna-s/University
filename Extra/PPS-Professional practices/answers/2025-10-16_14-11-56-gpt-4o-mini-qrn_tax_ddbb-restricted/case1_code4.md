| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 7 | `from qiskit import Aer` | Deprecation -> The Aer module is deprecated and will be removed in a future version | qrn_tax_ddbb-b97fd7b9-8ffe-4d5f-9f6a-a6427076bd5b | qiskit | `from qiskit_aer import Aer` | 
| 8 | `backend = Aer.get_backend('aer_simulator')` | Structural change -> Use backends from qiskit.providers.basic_provider | qrn_tax_ddbb-dd54f269-d2e3-4a45-a285-a01443c4ccef | Aer | `from qiskit.providers.basic_provider import BasicProvider\nbackend = BasicProvider().get_backend('basic_simulator')` | 

```python
import os

from qiskit import QuantumCircuit 
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

from qiskit_aer import Aer
from qiskit.providers.basic_provider import BasicProvider
backend = BasicProvider().get_backend('basic_simulator')

from utils import getJob
from datetime import datetime
job = getJob(qc, backend, 1000).result().get_counts(qc)

import matplotlib.pyplot as plt
qc.draw(output='mpl')
plt.show()
```