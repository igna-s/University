| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit import QuantumCircuit, qasm, execute | Deprecation -> qiskit.qasm module removed, use qiskit.qasm2 instead | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | qiskit.qasm | from qiskit import QuantumCircuit, execute |
| 3 | from qiskit import QuantumCircuit, qasm, execute | Deprecation -> qiskit.qasm import deprecated, remove 'qasm' from import | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | qiskit.qasm | from qiskit import QuantumCircuit, execute |

```python  
import os
from datetime import datetime
from qiskit import QuantumCircuit, execute
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = execute(qc, getMyBackend(), shots=1000)
result = job.result().get_counts(qc)
plt.show()
```