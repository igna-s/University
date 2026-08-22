| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> Qasm class is deprecated | IK | qiskit.qasm.Qasm | `# removed due to deprecation` |
| 5 | `from qiskit.algorithms import VQE` | Optional -> VQE import unused | IK | qiskit.algorithms.VQE | `# optional: unused import, can be removed` |
| 6 | `from qiskit import qasm2 as qasm` | Optional -> qasm2 import unused | IK | qiskit.qasm.qasm2 | `# optional: unused import, can be removed` |

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