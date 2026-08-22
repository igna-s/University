| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> `Aer` is no longer directly available from `qiskit` | Internal Knowledge | Aer | |
| 4 | `from qiskit import qasm` | Deprecation -> `qiskit.qasm` module has been removed | Internal Knowledge | qasm | |


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