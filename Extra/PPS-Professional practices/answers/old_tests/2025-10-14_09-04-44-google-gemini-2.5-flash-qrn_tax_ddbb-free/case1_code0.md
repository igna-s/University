| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> `qiskit.qasm` module has been removed | Internal Knowledge | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> `VQE` has moved from `qiskit.algorithms` to `qiskit.algorithms.minimum_eigensolvers` | Internal Knowledge | VQE | |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module has been removed | Internal Knowledge | qiskit.qasm2 | |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```