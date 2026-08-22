| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :-------- | :--------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | qiskit.qasm | # removed deprecated import |
| 6 | `from qiskit import qasm2 as qasm` | Optional -> unused qasm2 import | IK | qiskit.qasm2 | # removed unused import |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
