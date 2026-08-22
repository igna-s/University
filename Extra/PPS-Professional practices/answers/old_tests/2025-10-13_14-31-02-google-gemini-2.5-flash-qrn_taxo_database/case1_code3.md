| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of execute() function | 25 | e87b5b50-19b6-479a-8677-ad049ae04f4d | execute() | `from qiskit import QuantumCircuit` |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.Aer object | 4 | cecec3a7-b4db-460c-9d8f-04fcc44e7216 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm | `from qiskit import qasm2` |
| 14 | `job = getJob(qc, backend, 1000)` | Deprecation -> Deprecation of execute() function | 25 | e87b5b50-19b6-479a-8677-ad049ae04f4d | execute() | `job = backend.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit_aer import Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```