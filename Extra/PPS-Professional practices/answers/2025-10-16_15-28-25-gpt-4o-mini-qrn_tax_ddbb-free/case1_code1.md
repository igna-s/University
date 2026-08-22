| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import qasm2` |
| 3 | `from qiskit import Aer` | Deprecation -> The qiskit.Aer object is deprecated | qrn_tax_ddbb--0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import Aer` |

```python  
import os
from qiskit import QuantumCircuit
from qiskit import Aer
from qiskit import qasm2
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```