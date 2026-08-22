| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qiskit.qasm` module is deprecated | qrn_tax_ddbb-f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `execute()` function is deprecated | qrn_tax_ddbb-d7e68a47-8d01-4433-a93c-1aebfca5d9f4 | execute() | `from qiskit import QuantumCircuit, transpile` |
| 13 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> `execute()` function is deprecated. | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `transpiled_qc = transpile(qc, getMyBackend())` <br> `job = getMyBackend().run(transpiled_qc, shots=1000)` |
| 14 | `result = job.result().get_counts(qc)` | Deprecation -> `result.get_counts()` (optional) The `get_counts()` method is still available but it is recommended to use `result.quasi_dists[0].binary_probabilities()` for more generic result handling. | IK | get_counts() | `result = job.result().quasi_dists[0].binary_probabilities()` |


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

transpiled_qc = transpile(qc, getMyBackend())
job = getMyBackend().run(transpiled_qc, shots=1000)
result = job.result().quasi_dists[0].binary_probabilities()
plt.show()
```