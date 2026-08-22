| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm | `from qiskit import qasm2` |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module has been deprecated | * | Internal Knowledge | qiskit.algorithms | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm2` module is preferred over the legacy `qiskit.qasm` | * | ace97a00-7ee7-4af5-9a34-359da7578661 | qiskit.qasm2 | |


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