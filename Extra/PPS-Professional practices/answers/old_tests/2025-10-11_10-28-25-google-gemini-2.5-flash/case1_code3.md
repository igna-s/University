| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of execute() function | 27 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute() | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.Aer object | 6 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Deprecation of qiskit.qasm module | 16 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() is deprecated | * | internal | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000)` | Deprecation -> Deprecation of execute() function | 27 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute() | `job = backend.run(qc, shots=1000)` |


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