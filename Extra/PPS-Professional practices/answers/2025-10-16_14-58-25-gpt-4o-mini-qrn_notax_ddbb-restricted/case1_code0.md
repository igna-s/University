| Line | Code                                       | Scenario                                                    | Reference                                         | Artifact                             | Refactoring                                                 |
| :--: | :----------------------------------------- | :--------------------------------------------------------- | :----------------------------------------------- | :----------------------------------- | :--------------------------------------------------------- |
| 3    | `from qiskit.qasm import Qasm`           | Deprecation -> The qasm module is deprecated               | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm                          | `from qiskit import qasm2`                                 |
| 6    | `from qiskit import qasm2 as qasm`       | Updated -> Use of qasm2 instead of deprecated qasm module | IK                                              | qiskit.qasm2                        | `from qiskit import qasm2`                                 |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit import qasm2

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```