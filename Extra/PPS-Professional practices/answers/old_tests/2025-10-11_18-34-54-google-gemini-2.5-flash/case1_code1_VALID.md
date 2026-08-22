| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> The `Aer` provider is deprecated in qiskit >=1.0.0 | * | internal | `qiskit.Aer` | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> The `qasm` module is removed in qiskit >=1.0.0 | * | internal | `qiskit.qasm` | *(removed)* |

```python
import os
from qiskit import QuantumCircuit   # type: ignore
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
