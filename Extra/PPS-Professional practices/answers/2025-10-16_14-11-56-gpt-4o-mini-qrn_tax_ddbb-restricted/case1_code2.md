| Line | Code                                                 | Scenario                                                       | Reference                                           | Artifact                                     | Refactoring                                                     |
|------|------------------------------------------------------|----------------------------------------------------------------|----------------------------------------------------|----------------------------------------------|----------------------------------------------------------------|
| 3    | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The qiskit.qasm module is deprecated           | qrn_tax_ddbb-14b6858e-013f-4dc4-bc5b-cec408c7c3aa | qiskit.qasm                                 | `from qiskit import qasm2`                                    |
| 9    | `job = execute(qc, getMyBackend(), shots=1000)`    | Deprecation -> The execute() function is deprecated           | qrn_tax_ddbb-48a35b67-b938-487b-aef2-7b4596ff4105 | qiskit.execute                               | `job = backend.run(transpile(qc))`                             |
| 11   | `import matplotlib.pyplot as plt`                     | Deprecation -> The plot_histogram() function now uses        | qrn_tax_ddbb-2c964caa-447e-4f83-9e59-41f1a5d2f408 | matplotlib.pyplot                             | `from qiskit.visualization import plot_distribution`          |
| 13   | `result = job.result().get_counts(qc)`               | Deprecation -> The method get_counts() needs qasm2           | qrn_tax_ddbb-08dc28ea-fc4b-4d33-81f2-8cb098965c3e | qiskit.result                                | `result = job.result().get_counts(qc)`                       |

```python  
import os
from datetime import datetime
from qiskit import QuantumCircuit, qasm2, transpile
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = getMyBackend()
job = backend.run(transpile(qc))
result = job.result().get_counts(qc)
plt.show()
```