| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module has been deprecated | Internal Knowledge | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms.VQE` has moved | qrn_ddbb-f1a5 | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```