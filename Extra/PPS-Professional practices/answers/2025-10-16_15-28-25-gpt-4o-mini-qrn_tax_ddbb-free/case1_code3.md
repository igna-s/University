| Line | Code                                                      | Scenario                                                      | Reference                                              | Artifact                 | Refactoring                                             |
| :--: | :------------------------------------------------------- | :-------                                                    | :---------------------------------------------------- | :----------------------- | :----------------------------------------------------- |
| 4    | `from qiskit import execute`                             | Deprecation -> The execute() function is deprecated        | d7e68a47-8d01-4433-a93c-1aebfca5d9f4                  | qiskit                  | `from qiskit import transpile`                        |
| 5    | `backend = Aer.get_backend('aer_simulator')`            | Deprecation -> Import from qiskit.providers.aer is deprecated | 0771d384-706f-40c0-818d-20a4b728e9a2                  | Aer                     | `backend = qiskit_aer.Aer.get_backend('aer_simulator')` |
| 8    | `result = job.result().get_counts(qc)`                  | Deprecation -> The execute() function is deprecated        | d7e68a47-8d01-4433-a93c-1aebfca5d9f4                  | qiskit                  | `result = backend.run(qc).result()`                   |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, transpile, Aer
import matplotlib.pyplot as plt
from utils import getJob

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = Aer.get_backend('aer_simulator')
job = getJob(qc, backend, 1000)
result = backend.run(qc).result()
plt.show()
```