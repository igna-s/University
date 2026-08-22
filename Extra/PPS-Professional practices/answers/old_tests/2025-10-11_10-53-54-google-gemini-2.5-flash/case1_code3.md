| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | 1f5a35a2-9fb1-431b-8aec-35c0fe26e1bf | qiskit.providers.aer | `backend = Aer.get_backend('aer_simulator')` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```