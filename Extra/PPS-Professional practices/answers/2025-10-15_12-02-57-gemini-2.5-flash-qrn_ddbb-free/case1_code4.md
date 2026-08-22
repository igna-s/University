| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 13 | `from qiskit import Aer` | Deprecation -> Importing from `qiskit.providers.aer` is deprecated and will stop working in Qiskit 1.0. You should instead import from `qiskit_aer`, which is a drop-in replacement. | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 14 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from `qiskit.providers.aer` is deprecated and will stop working in Qiskit 1.0. You should instead import from `qiskit_aer`, which is a drop-in replacement. | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend | `backend = AerSimulator()` |
| 20 | `qc.draw(output='mpl')` | Deprecation -> The `qiskit.visualization.qcstyle` module is now deprecated and will be removed in the Qiskit 1.0.0 release. Instead you should use `qiskit.visualization.circuit.qcstyle` as direct replacement. | qrn_notax_ddbb--51d2433e-bdaf-4b3e-8782-e604a1676902 | qc.draw | `fig = qc.draw(output='mpl')` |


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
fig = qc.draw(output='mpl')
plt.show()
```