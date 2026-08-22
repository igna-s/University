| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated. | IK | qiskit.qasm |  |
| 5 | `from qiskit.algorithms import VQE` | Metapackage update -> The VQE algorithm is now located in the qiskit_algorithms package. | IK | qiskit.algorithms | `from qiskit_algorithms import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | New Module -> The qiskit.qasm2 module is new in Qiskit version 1.0. | IK | qiskit.qasm2 |  |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit_algorithms import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```