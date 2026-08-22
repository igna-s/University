| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 4 | from qiskit.qasm import Qasm | Deprecation -> Qasm class is deprecated in favor of qiskit.qasm2 and not available in 1.0.0 | qrn_tax_ddbb-45d3e3bab853d456eefa94b9129e7d92 | qiskit.qasm.Qasm |  |
| 5 | from qiskit.algorithms import VQE | Updated -> qiskit.algorithms.VQE moved to qiskit_algorithms package | qrn_tax_ddbb-d2211137456c4e07c1a1461efb3ebcf0 | qiskit.algorithms.VQE | from qiskit_algorithms import VQE |
| 6 | from qiskit import qasm2 as qasm | New library -> qiskit.qasm2 introduced as replacement for qiskit.qasm | qrn_tax_ddbb-1250fd1cf1da440799436b0c976dd8ce | qiskit.qasm2 |  |

```python
import os
from qiskit import QuantumCircuit
from datetime import datetime
from qiskit_algorithms import VQE
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

print("work done !")
```