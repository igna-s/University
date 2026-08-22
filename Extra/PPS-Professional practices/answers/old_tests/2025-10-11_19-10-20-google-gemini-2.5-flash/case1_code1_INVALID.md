| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> Aer provider is deprecated and will be removed in a future release. | 9c943351-4144-414e-b65f-421480f95203 | internal | Aer | `from qiskit_aer import AerSimulator` |
| 3 | `from qiskit import Aer              # type: ignore` | Replacement -> Replace deprecated Aer provider with new AerSimulator | 9c943351-4144-414e-b65f-421480f95203 | internal | Aer |  |
| 4 | `from qiskit import qasm             # type: ignore` | Removal -> The qasm module has been removed. | * | internal | qasm |  |

```python
import os
from qiskit import QuantumCircuit   # type: ignore
from qiskit_aer import AerSimulator
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```