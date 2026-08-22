| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. You should instead use the same object from the qiskit_aer namespace, which is a drop-in replacement. | 4e1a7f69-eeb4-4a93-9f27-322819438bf4 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated and will be removed in Qiskit 1.0. This module has been superseded by qiskit.qasm2, qiskit.qasm3. | IK | qiskit.qasm | |

```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```