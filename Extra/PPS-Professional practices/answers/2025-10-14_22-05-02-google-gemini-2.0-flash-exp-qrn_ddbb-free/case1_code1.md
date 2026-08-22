| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Meta-package Deprecation -> The qiskit meta-package is deprecated. | qrn_ddbb-28a82238863ca98a57306846951f0932 | qiskit | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Removal -> The qasm module has been removed. | qrn_ddbb-1671044323138d93540b12b4b3407342 | qiskit.qasm |  |

```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```