| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of execute() function | 25 | 3fe9c4ed-0515-48f3-b692-bbc5a124f8e6 | execute | remove execute from import and use `backend.run()` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.Aer object | 4 | bb13d578-c8e9-44dd-8431-861cea75d5de | Aer | `from qiskit_aer import Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qasm | remove qasm from import |
| 14 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Deprecation of qiskit.Aer object | 4 | bb13d578-c8e9-44dd-8431-861cea75d5de | Aer.get_backend | `backend = AerSimulator()` |
| 15 | `job = getJob(qc, backend, 1000)` | Deprecation -> Deprecation of execute() function | 25 | 3fe9c4ed-0515-48f3-b692-bbc5a124f8e6 | execute | `job = backend.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt
from utils import getJob

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