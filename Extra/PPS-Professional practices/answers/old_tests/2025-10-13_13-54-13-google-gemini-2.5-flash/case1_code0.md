| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
|:--:|:---|:---------|:-----------:|:----------:|:--------|:------------|
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm.Qasm removed | * | Internal Knowledge | Qiskit.qasm.Qasm | |
| 6 | `from qiskit import qasm2 as qasm` | Migration -> Updated import path for qasm2 module | * | Internal Knowledge | qiskit.qasm2 | `from qiskit.qasm2 import qasm` |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE
from qiskit.qasm2 import qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```
