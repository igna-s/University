| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module has been removed. | Internal Knowledge | `qiskit.qasm.Qasm` | |
| 5 | `from qiskit.algorithms import VQE` | Updated -> `VQE` has moved to `qiskit.algorithms.minimum_eigensolvers`. | Internal Knowledge | `qiskit.algorithms.VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm2` module has been removed. | Internal Knowledge | `qiskit.qasm2` | |


```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms.minimum_eigensolvers import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```