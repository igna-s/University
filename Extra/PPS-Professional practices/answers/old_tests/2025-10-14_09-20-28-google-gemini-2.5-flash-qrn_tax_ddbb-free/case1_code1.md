| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Aer moved to `qiskit_aer` package | Internal Knowledge | Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> The `qiskit.qasm` module is removed or moved | Internal Knowledge | qasm | |


```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```