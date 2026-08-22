| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> `from qiskit import Aer` is deprecated | qrn_tax_ddbb-0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | Remove import |
| 4 | `from qiskit import qasm` | Deprecation -> `from qiskit import qasm` is deprecated | qrn_tax_ddbb-f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | Remove import |

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
