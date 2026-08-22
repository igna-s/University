| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit import QuantumCircuit, qasm, execute | Deprecation -> `execute` function is deprecated and should be replaced with `Backend.run` | qrn_notax_ddbb--3dcf0876-6d32-4d0d-91b5-106daf8b4612 | qiskit.execute |  from qiskit import QuantumCircuit |
| 9 | job = execute(qc, getMyBackend(), shots=1000) | Deprecation -> `execute` function is deprecated; use `backend.run` method instead | qrn_notax_ddbb--3dcf0876-6d32-4d0d-91b5-106daf8b4612 | qiskit.execute | backend = getMyBackend(); job = backend.run(qc, shots=1000) |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = getMyBackend()
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```