| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Aer class is deprecated, replaced by AerSimulator | IK | qiskit.Aer | `from qiskit.providers.aer import AerSimulator` |
| 4 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module is deprecated | IK | qiskit.qasm |  |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```