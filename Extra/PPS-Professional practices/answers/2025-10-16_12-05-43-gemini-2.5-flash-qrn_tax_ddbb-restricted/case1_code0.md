| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated | qrn_tax_ddbb-d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```