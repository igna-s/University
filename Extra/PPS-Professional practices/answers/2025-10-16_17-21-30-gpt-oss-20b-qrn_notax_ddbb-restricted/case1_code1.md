| Line | Code                                 | Scenario                                      | Reference                                    | Artifact | Refactoring |
|:----:|-------------------------------------|----------------------------------------------|----------------------------------------------|----------|-------------|
| 3    | `from qiskit import Aer`             | Deprecation -> Aer import is deprecated in Qiskit 1.0.0 | 4194776d-c578-4b79-8dc6-9c5e286bc808          | Aer      | Remove the import (not used in the code) |
| 4    | `from qiskit import qasm`            | Deprecation -> qiskit.qasm module is deprecated | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24          | qasm     | Remove the import (not used in the code) |

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
