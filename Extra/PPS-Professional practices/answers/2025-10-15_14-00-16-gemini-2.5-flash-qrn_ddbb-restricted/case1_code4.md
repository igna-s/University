| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> The qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | qrn_notax_ddbb-4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | `from qiskit_aer import Aer` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | qrn_notax_ddbb-548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend | `backend = AerSimulator()` |
| 17 | `qc.draw(output='mpl')` | New functionality -> The QuantumCircuit.draw method in Qiskit 1.0 no longer supports the 'mpl' output directly. Instead, you should import and use the 'mpl_drawer' function from 'qiskit.visualization.circuit.mpl' for Matplotlib-based drawing. | IK | qc.draw | `mpl_drawer(qc)` |


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
from qiskit.visualization.circuit.mpl import mpl_drawer
mpl_drawer(qc)
plt.show()
```