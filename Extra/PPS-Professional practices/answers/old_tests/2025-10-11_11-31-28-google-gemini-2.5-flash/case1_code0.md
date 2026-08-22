| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> `qiskit.qasm` module removed | 16 | 64d97f25-3330-4e89-a5e2-e1a5d0ce1349 | qiskit.qasm | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> `qiskit.algorithms` module removed. Algorithms moved to `qiskit.algorithms.minimum_eigensolvers` | 13 | 43d700e5-7b56-4277-a8a5-c277636e1d6d | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |


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

print("work done !")
```