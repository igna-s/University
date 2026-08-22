| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated. | 94404130-7a16-41f5-994a-53c439775723 | internal | qiskit.qasm |  |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> Class `VQE` is deprecated and will be removed no earlier than 3 months after the release date. | 7f84576d-1e5f-4398-9450-86a7a5235107 | internal | qiskit.algorithms.VQE |  |
| 6 | `from qiskit import qasm2 as qasm` | Package rename -> The package qiskit.qasm2 has been renamed to qiskit.qasm | 09483a13-4d21-447c-b19c-29c999989c98 | internal | qiskit.qasm2 | `from qiskit import qasm` |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit import qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```