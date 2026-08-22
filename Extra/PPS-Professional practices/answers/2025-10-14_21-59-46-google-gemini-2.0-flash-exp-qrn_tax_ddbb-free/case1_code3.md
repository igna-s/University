| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `import os` | No change | IK | os | No change |
| 2 | `from datetime import datetime` | No change | IK | datetime | No change |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qasm` module is deprecated and will be removed in a future release. | qrn_tax_ddbb-931c2a817b114b1685634a4cf04a197e | qasm | `from qiskit import QuantumCircuit, execute, Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` |  Removal -> The global `execute` function is removed in favor of the `Estimator`, `Sampler` and `QasmSimulator` primitives. | qrn_tax_ddbb-c55d0c6964d54293b354a97983419492 | execute | `from qiskit import QuantumCircuit, Aer` |
| 4 | `import matplotlib.pyplot as plt` | No change | IK | matplotlib.pyplot | No change |
| 5 | `from utils import getJob` | No change | IK | utils | No change |
| 10 | `backend = Aer.get_backend('aer_simulator')` | No change | IK | Aer | No change |
| 11 | `job = getJob(qc, backend, 1000)` | No change | IK | getJob | No change |
| 12 | `result = job.result().get_counts(qc)` | No change | IK | result | No change |
| 13 | `plt.show()` | No change | IK | plt | No change |

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