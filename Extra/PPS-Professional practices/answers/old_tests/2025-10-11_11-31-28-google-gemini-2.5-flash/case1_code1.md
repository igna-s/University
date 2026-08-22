| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer` | Deprecation -> Deprecation of qiskit.Aer object | * | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | * | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit import qasm2` |


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