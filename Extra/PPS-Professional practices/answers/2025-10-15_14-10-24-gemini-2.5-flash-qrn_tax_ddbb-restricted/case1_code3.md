| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `execute()` function is deprecated | 039bc9ef-72bf-4376-9047-3e418906d0e0 | execute | (removed) |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> Importing from `qiskit.Aer` is deprecated | 084696d9-2c75-437a-8e84-96506e6766aa | Aer | `from qiskit_aer import AerSimulator` |
| 4 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qiskit.qasm` module is deprecated | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qasm | (removed) |
| 13 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated | 084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `job = getJob(qc, backend, 1000)` | Deprecation -> The `execute` function (which `getJob` likely wraps) is deprecated | 039bc9ef-72bf-4376-9047-3e418906d0e0 | execute | `job = backend.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt

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