| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qiskit.Aer` module is deprecated. | * | internal | `Aer` | (removed from import) |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qiskit.execute()` function is deprecated and should be replaced with `backend.run()`. (optional) | * | internal | `execute` | (removed from import) |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. (optional) | * | internal | `qasm` | (removed from import) |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | * | internal | `Aer.get_backend` | `backend = AerSimulator()` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```