| Line | Code | Scenario | Reference | Artifact | Refactoring |
|------|------|----------|-----------|----------|-------------|
| 3 | `from qiskit import Aer` | Deprecation -> The Aer provider from qiskit is deprecated | qrn_ddbb-dac4df2e-7a08-4097-b150-0993e5d8d792 | Aer | Delete import |
| 4 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | qasm | Delete import |

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
