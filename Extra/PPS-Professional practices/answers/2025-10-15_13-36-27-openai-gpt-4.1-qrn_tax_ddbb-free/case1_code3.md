| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | from qiskit import QuantumCircuit, execute, Aer, qasm | Deprecation -> `execute` and `qasm` import behavior changed, `qasm` module removed | qrn_tax_ddbb--c14adc03-d94b-425b-b35e-7357a3efb80f | execute, qasm | from qiskit import QuantumCircuit, Aer |
| 12 | job = getJob(qc, backend, 1000) | API Change -> Passing shots as positional argument to custom function should follow Qiskit pattern (optional) | IK | getJob | |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, Aer
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