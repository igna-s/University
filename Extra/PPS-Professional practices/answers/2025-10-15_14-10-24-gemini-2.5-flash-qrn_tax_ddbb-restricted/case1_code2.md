| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `qiskit.qasm` module is deprecated | qrn_tax_ddbb-f24d40d4-9a98-4431-85f5-3e6f98fee373 | `qiskit.qasm` | `from qiskit import QuantumCircuit, transpile` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `execute()` function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | `execute` | `from qiskit import QuantumCircuit, transpile` |
| 11 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> The `execute()` function is deprecated | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | `execute` | `backend = getMyBackend()` <br> `transpiled_qc = transpile(qc, backend)` <br> `job = backend.run(transpiled_qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, transpile
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = getMyBackend()
transpiled_qc = transpile(qc, backend)
job = backend.run(transpiled_qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```