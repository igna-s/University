| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm.Qasm import removed | * | Internal Knowledge | qiskit.qasm.Qasm | Remove this import line. |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> qiskit.algorithms.VQE import deprecated (unused) | * | Internal Knowledge | qiskit.algorithms.VQE | Remove this import line. |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> qiskit.qasm2 alias unused | * | Internal Knowledge | qiskit.qasm2 | Remove this import line. |

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