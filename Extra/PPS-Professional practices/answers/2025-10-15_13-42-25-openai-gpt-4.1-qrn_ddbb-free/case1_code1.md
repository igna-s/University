| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | from qiskit import qasm | Deprecation -> qiskit.qasm deprecated and removed in 1.0.0 | qrn_notax_ddbb--e134b8e9-6c21-47d8-bb0f-cf0a8d321024 | qiskit.qasm |  |
|  |  |  |  |  |  |

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