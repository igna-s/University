| Line | Code                                               | Scenario                                                        | Reference                                         | Artifact                          | Refactoring                               |
| :--: | :------------------------------------------------ | :------------------------------------------------------------- | :---------------------------------------------- | :--------------------------------- | :---------------------------------------- |
| 4    | `from qiskit.qasm import Qasm`                    | Deprecation -> Qasm module is deprecated                      | IK                                               | qiskit.qasm                        | `from qiskit import qasm2`               |
| 5    | `from qiskit import qasm2 as qasm`                | No change                                                      | IK                                               | qiskit.qasm2                       |                                           |
| 1    | `qc = QuantumCircuit(2, 2)`                        | No change                                                      | IK                                               | QuantumCircuit                     |                                           |
| 2    | `qc.h(0)`                                         | No change                                                      | IK                                               | QuantumCircuit                     |                                           |
| 3    | `qc.cx(0, 1)`                                     | No change                                                      | IK                                               | QuantumCircuit                     |                                           |
| 4    | `qc.measure(0, 0)`                                | No change                                                      | IK                                               | QuantumCircuit                     |                                           |
| 5    | `qc.measure(1, 1)`                                | No change                                                      | IK                                               | QuantumCircuit                     |                                           |
| 8    | `print("work done !")`                            | No change                                                      | IK                                               | print                             |                                           |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```