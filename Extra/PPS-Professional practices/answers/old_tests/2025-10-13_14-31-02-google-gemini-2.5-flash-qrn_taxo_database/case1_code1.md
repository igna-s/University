| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | 4 | cecec3a7-b4db-460c-9d8f-04fcc44e7216 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm | `from qiskit import qasm2` |


```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit import qasm2
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```