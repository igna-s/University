| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> legacy OpenQASM 2 parser module deprecated | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | remove import |
| 5 | `from qiskit.algorithms import VQE` | (optional) unused import |  | qiskit.algorithms | remove import |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```