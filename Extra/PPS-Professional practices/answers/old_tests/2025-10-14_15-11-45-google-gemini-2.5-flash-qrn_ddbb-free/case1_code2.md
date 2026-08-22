| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `qasm` module is deprecated. (optional) | Internal Knowledge | qasm | |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> `execute` function is deprecated. | qrn_ddbb-5054 | execute | `from qiskit.transpiler import PassManager` |
| 12 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> `execute` function is deprecated. | qrn_ddbb-5054 | execute | `from qiskit.transpiler import PassManager` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit.transpiler import PassManager
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

backend = getMyBackend()
transpiled_qc = PassManager().run(qc)
job = backend.run(transpiled_qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```