| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qiskit.qasm` module is deprecated | Internal Knowledge | `qasm` | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qiskit.execute` function is deprecated | Internal Knowledge | `execute` | `from qiskit import QuantumCircuit` |
| 11 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> `execute` function replaced by `backend.run()` method | Internal Knowledge | `execute` | `backend = getMyBackend()`<br>`job = backend.run(qc, shots=1000)` |


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