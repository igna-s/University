| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` |  Removal -> The qasm module has been removed from Qiskit Terra | qrn_ddbb-a955995b17a8b953552ca49579c7c96b | qasm | `from qiskit import QuantumCircuit, execute` |
| 4 | `import matplotlib.pyplot as plt` | Deprecation -> Support for mpl deprecated in terra  | qrn_ddbb-27f3b | matplotlib.pyplot |   |

```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = execute(qc, getMyBackend(), shots=1000)
result = job.result().get_counts(qc)
plt.show()
```