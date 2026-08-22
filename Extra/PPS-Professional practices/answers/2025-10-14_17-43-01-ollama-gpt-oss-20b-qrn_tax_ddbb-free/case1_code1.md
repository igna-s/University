| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:--------|:--------:|:--------|:------------|
| 4 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module is deprecated | IK | qiskit.qasm | `# import removed` |

```python
import os
from qiskit import QuantumCircuit
from qiskit import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
