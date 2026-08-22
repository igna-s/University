| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Removal -> The alias `qasm` is removed in Qiskit 1.0.  | qrn_tax_ddbb-59659c3b-4c18-4b57-bc99-4d9211163993 | qasm | Remove the import of `qasm` from `qiskit`. |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute, Aer
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