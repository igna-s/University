| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.qasm import Qasm` | Deprecation -> `qiskit.qasm` module and `Qasm` class are deprecated and removed. | Internal Knowledge | `qiskit.qasm.Qasm` | |
| 4 | `from qiskit.algorithms import VQE` | Restructure -> `VQE` moved to `qiskit.algorithms.minimum_eigensolvers`. | Internal Knowledge | `qiskit.algorithms.VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 5 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is deprecated. | Internal Knowledge | `qiskit.qasm2` | |


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

print("work done !")
```