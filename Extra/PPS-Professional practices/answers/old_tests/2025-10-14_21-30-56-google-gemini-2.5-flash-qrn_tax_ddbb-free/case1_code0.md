| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated | qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | `qiskit.qasm` | |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> The `qiskit.algorithms` module is deprecated | IK | `qiskit.algorithms` | `from qiskit.primitives import Estimator` |
| 6 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm` module is superseded by `qiskit.qasm2` | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | `qiskit.qasm` | `import qiskit.qasm2 as qasm` |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit.primitives import Estimator
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

# print
print("work done !")
```