| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer # type: ignore` | Deprecation -> qiskit.Aer object is deprecated | f4629adb-1cfe-4469-9df9-d8d0172ab667 | internal | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm # type: ignore` | Deprecation -> qiskit.qasm module is deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | internal | qiskit.qasm | `from qiskit.qasm import QASM2Parser` |


```python
import os
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.qasm import QASM2Parser
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```