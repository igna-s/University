| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> `Qasm` module removed | IK | qiskit.qasm.Qasm | remove this line |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> `qasm2` import alias deprecated | IK | qiskit.qasm.qasm2 | replace with `from qiskit.qasm import qasm2 as qasm` |
```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.algorithms import VQE

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```