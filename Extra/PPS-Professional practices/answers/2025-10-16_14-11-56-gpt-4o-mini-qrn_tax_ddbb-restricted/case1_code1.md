| Line | Code                                                      | Scenario                                                        | Reference                                              | Artifact                            | Refactoring                                        |
|:----:|:--------------------------------------------------------|:---------------------------------------------------------------|:-----------------------------------------------------|:------------------------------------|:--------------------------------------------------|
| 3   | `from qiskit import qasm`                               | Deprecation -> The qasm module is deprecated                   | qrn_tax_ddbb-14f8f707-2443-4013-a8cf-2f93f4c07569    | qiskit.qasm                        | `from qiskit import qasm2`                       |
| 5   | `qc = QuantumCircuit(2, 2)`                            | -                                                             | IK                                                   | QuantumCircuit                     | -                                                |
| 6   | `qc.h(0)`                                              | -                                                             | IK                                                   | QuantumCircuit                     | -                                                |
| 7   | `qc.cx(0, 1)`                                          | -                                                             | IK                                                   | QuantumCircuit                     | -                                                |
| 8   | `qc.measure(0, 0)`                                     | -                                                             | IK                                                   | QuantumCircuit                     | -                                                |
| 9   | `qc.measure(1, 1)`                                     | -                                                             | IK                                                   | QuantumCircuit                     | -                                                |
| 11  | `print("work done !")`                                 | -                                                             | IK                                                   | print                             | -                                                |

```python
import os
from qiskit import QuantumCircuit
from qiskit import Aer
from qiskit import qasm2
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```