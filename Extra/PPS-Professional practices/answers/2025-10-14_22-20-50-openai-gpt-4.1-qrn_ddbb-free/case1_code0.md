| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | from qiskit.qasm import Qasm | Deprecation -> qiskit.qasm.Qasm is removed | qrn_ddbb-39c97b086b75378f197e4b7dc049112b | qiskit.qasm.Qasm |  |
| 6 | from qiskit import qasm2 as qasm | Updated -> qasm2 separate package import now required | qrn_ddbb-ab0705e1a76b49c793c85bc722c43b3e | qiskit.qasm2 | import qiskit_qasm2 as qasm |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE
import qiskit_qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```