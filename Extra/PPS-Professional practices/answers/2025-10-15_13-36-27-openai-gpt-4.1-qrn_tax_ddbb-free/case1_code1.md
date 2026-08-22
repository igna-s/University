| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | from qiskit import qasm | Deprecation -> The qiskit.qasm module is deprecated and removed | qrn_tax_ddbb--e430bb0f-bbd8-4e68-841a-6a06e49809ba | qiskit.qasm |  |

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