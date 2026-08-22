| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer # type: ignore` | Deprecation -> Importing from qiskit.providers.aer is deprecated and will stop working in Qiskit 1.0. You should instead import from qiskit_aer, which is a drop-in replacement. | d632081c-97e1-4fa4-b5aa-e11204bcd570 | qiskit.Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm # type: ignore` | Deprecation -> The qiskit.qasm module has been deprecated | internal | qiskit.qasm | |


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