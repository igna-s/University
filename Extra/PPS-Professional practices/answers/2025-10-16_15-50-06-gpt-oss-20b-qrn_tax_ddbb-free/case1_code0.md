| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | Remove this import |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```
