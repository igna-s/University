| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | from qiskit import QuantumCircuit, execute, Aer, qasm | Deprecation -> qiskit.Aer object is deprecated; qasm import is deprecated | qrn_tax_ddbb-c02fdd64-b33a-477c-a00d-105424346f39, qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | Aer, qasm | from qiskit_aer import Aer<br>from qiskit import QuantumCircuit, execute |
| 8 | backend = Aer.get_backend('aer_simulator') | Namespace change -> Use Aer from qiskit_aer | qrn_tax_ddbb-c02fdd64-b33a-477c-a00d-105424346f39 | Aer | backend = Aer.get_backend('aer_simulator') |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = getJob(qc, backend, 1000)
result = job.result().get_counts(qc)
plt.show()
```