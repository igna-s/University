| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> Aer import changed | IK | Aer | Remove the line |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> qasm module removed | IK | qasm | Remove the line |

```python
import os
from qiskit import QuantumCircuit   # type: ignore
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
