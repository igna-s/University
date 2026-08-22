| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit import QuantumCircuit, execute, Aer, qasm | Deprecation -> qasm is removed from the main import path | qrn_notax_ddbb--9249fe3e-2fd9-412a-82e6-3cdfdfa7a660 | qiskit.qasm | Remove qasm from imports; if required, use qiskit.qasm if still needed in dependency. |
| 7 | backend = Aer.get_backend('aer_simulator') | Update -> Aer.get_backend is deprecated. Use AerSimulator directly. | qrn_notax_ddbb--23e6b20d-e431-4845-9e71-46e3c12e053e | Aer.get_backend | from qiskit_aer import AerSimulator; backend = AerSimulator() |
| 8 | job = getJob(qc, backend, 1000) | API update -> Shots as parameter changed in run method | qrn_notax_ddbb--68c4cdc3-94f6-4f4c-8a42-56bbc8bfb99f | backend execution | job = getJob(qc, backend, shots=1000) or ensure getJob uses backend.run(qc, shots=1000) |

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
job = getJob(qc, backend, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```