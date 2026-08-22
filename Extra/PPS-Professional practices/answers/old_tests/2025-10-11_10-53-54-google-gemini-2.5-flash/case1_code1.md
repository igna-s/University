| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer # type: ignore` | Deprecation -> Deprecation of qiskit.Aer object | f4629adb-1cfe-4469-9df9-d8d0172ab667 | f4629adb-1cfe-4469-9df9-d8d0172ab667 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm # type: ignore` | Deprecation -> The qiskit.qasm module is deprecated and will be removed in a future release. | * | internal | qiskit.qasm | `from qiskit.converters import circuit_to_qasm_str` |


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