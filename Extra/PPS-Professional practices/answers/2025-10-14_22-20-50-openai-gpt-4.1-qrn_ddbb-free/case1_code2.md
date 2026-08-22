| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit import QuantumCircuit, qasm, execute | Deprecation -> qiskit.execute() is deprecated | qrn_ddbb-aa9de6d6b9554ccebc85b3ab68901884 | qiskit.execute | Remove usage of `execute`; use `backend.run()` instead |
| 10 | job = execute(qc, getMyBackend(), shots=1000) | Deprecation -> qiskit.execute() is deprecated | qrn_ddbb-aa9de6d6b9554ccebc85b3ab68901884 | qiskit.execute | job = getMyBackend().run(qc, shots=1000) |

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

job = getMyBackend().run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```