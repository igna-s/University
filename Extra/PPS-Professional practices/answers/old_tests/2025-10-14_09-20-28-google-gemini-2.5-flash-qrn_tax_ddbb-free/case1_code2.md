| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qasm` module is deprecated | Internal Knowledge | qasm | |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `execute` function is deprecated. Instead, the `run` method of a `Sampler` or `Estimator` object should be used. | qrn_tax_ddbb-50ad | execute | `from qiskit import QuantumCircuit` |
| 12 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> `execute` function is deprecated. Instead, the `run` method of a `Sampler` or `Estimator` object should be used. | qrn_tax_ddbb-50ad | execute | `backend = getMyBackend()`<br>`job = backend.run(qc, shots=1000)` |


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