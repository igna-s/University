| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 1 | `import os` | Removal of unused import | IK | import os | |
| 2 | `from datetime import datetime` | Removal of unused import | IK | datetime import | |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Updated -> Import of Aer from qiskit.providers.aer | IK | Aer | `from qiskit import QuantumCircuit\nfrom qiskit.providers.aer import Aer` |

```python
from qiskit import QuantumCircuit
from qiskit.providers.aer import Aer
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
