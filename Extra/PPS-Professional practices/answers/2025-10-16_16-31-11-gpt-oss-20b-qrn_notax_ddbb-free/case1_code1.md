| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> qiskit.Aer import is deprecated in Qiskit 1.0.0 | IK | Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> qiskit.qasm import is deprecated in Qiskit 1.0.0 | IK | qasm | `# from qiskit import qasm  # removed; use qiskit.qasm2 if needed` |

```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
# from qiskit import qasm  # removed; use qiskit.qasm2 if needed
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```
