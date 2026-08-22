| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:-------|:---------:|:---------|:-----------|
|10|`from qiskit import Aer`|Deprecation -> Importing from qiskit.providers.aer is deprecated, will stop working in Qiskit 1.0|qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0|Aer|`from qiskit_aer import AerSimulator`|
|11|`backend = Aer.get_backend('aer_simulator')`|Deprecation -> Aer.get_backend is deprecated, use AerSimulator class|qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0|Aer.get_backend|`backend = AerSimulator()`|

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
