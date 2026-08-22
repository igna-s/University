| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qasm` module removed from `qiskit` top-level import | Internal Knowledge | `qasm` | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `execute` function removed from `qiskit` top-level import | qrn_ddbb-1c3a | `execute` | `from qiskit import QuantumCircuit` |
| 13 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> `execute` function replaced by `backend.run()` | qrn_ddbb-1c3a | `execute` | `job = getMyBackend().run(qc, shots=1000)` |


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