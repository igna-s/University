| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated and its contents have been moved or removed. | Internal Knowledge | `qiskit.qasm` | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module has been deprecated. Algorithms are now typically found in `qiskit.algorithms.minimum_eigensolvers`. | Internal Knowledge | `qiskit.algorithms` | |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` is not a standard Qiskit 1.0.0 module for QASM parsing. | Internal Knowledge | `qiskit.qasm2` | |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```