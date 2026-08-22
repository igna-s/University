| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of qiskit.qasm module | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import qasm2` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of execute() function | qrn_tax_ddbb--48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `from qiskit import transpile` |
| 14 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Deprecation of execute() function | qrn_tax_ddbb--48a35b67-b938-487b-aef2-7b4596ff4105 | execute() | `transpiled_qc = transpile(qc, getMyBackend())`<br>`job = getMyBackend().run(transpiled_qc, shots=1000)` |


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
result = job.result().get_counts(qc)
plt.show()
```