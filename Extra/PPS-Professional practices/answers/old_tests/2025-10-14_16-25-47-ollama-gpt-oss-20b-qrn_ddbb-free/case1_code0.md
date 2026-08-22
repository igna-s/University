| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> Qasm class deprecated in Qiskit 1.0.0 | IK | Qasm | Remove this line |
| 6 | `from qiskit import qasm2 as qasm` | Optional -> unused import, remove | IK | qasm2 | Remove this line |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```
