| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import QuantumCircuit, Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb--48a35b67-b938-487b-aef2-7b4596ff4105 | execute | |
| 14 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_tax_ddbb--084696d9-2c75-437a-8e84-96506e6766aa | qiskit.providers.aer | `from qiskit_aer import AerSimulator` |
| 15 | `job = getJob(qc, backend, 1000)` | Deprecation -> The execute() function is deprecated | qrn_tax_ddbb--48a35b67-b938-487b-aef2-7b4596ff4105 | execute | `job = backend.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, Aer
import matplotlib.pyplot as plt
from utils import getJob
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = AerSimulator()
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```