| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> The `Aer` module has been removed from the top-level `qiskit` namespace. | Internal Knowledge | Aer | |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> The `qasm` module has been removed from the top-level `qiskit` namespace. | Internal Knowledge | qasm | |


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