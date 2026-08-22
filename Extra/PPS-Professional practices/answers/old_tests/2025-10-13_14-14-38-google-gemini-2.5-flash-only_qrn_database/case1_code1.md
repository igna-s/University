| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> Use of the qiskit.Aer object is deprecated and will be removed in Qiskit 1.0. | * | ce25a304-5b28-43b2-8a0d-9b31e0b13fb7 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | |


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