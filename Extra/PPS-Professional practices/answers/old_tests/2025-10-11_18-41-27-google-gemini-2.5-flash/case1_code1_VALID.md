| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :--------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> The Aer module is moved to qiskit.providers.aer | * | internal | qiskit.Aer |  |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> qiskit.qasm module removed | * | internal | qiskit.qasm |  |

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
