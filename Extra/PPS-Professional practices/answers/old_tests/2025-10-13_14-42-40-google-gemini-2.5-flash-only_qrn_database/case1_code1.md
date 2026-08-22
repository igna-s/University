| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Aer module moved to qiskit_aer | 3 | 0e960309-8664-4e3f-a18a-40a2c0c7b508 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 4 | `from qiskit import qasm` | Deprecation -> The qasm module is deprecated | 4 | 2277d343-4702-45e0-b6f7-c25227d853e3 | qiskit.qasm | |


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