| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import Aer` | Deprecation -> The `qiskit.Aer` module is deprecated. | Internal Knowledge | `Aer` | `from qiskit_aer import AerSimulator` |
| 3 | `from qiskit import qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. | Internal Knowledge | `qasm` | |


```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```