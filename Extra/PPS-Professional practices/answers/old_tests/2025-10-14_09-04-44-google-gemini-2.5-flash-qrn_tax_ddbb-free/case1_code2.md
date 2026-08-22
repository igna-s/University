| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `qasm` module is deprecated | Internal Knowledge | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `execute` function is deprecated | Internal Knowledge | qiskit.execute | `from qiskit import QuantumCircuit` |
| 14 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> The `execute` function is deprecated. Use `backend.run()` instead. | Internal Knowledge | execute | `job = getMyBackend().run(qc, shots=1000)` |


```python
    import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = getMyBackend().run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```