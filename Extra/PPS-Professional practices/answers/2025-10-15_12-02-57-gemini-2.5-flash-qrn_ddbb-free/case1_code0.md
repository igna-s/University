| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm.Qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module has been deprecated | IK | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm2 | |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```