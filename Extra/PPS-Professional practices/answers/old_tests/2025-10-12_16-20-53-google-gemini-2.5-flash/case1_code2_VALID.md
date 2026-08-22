| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `execute` function is deprecated | * | Internal Knowledge | execute | `from qiskit import QuantumCircuit` |
| 13 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> The `execute` function is deprecated | * | Internal Knowledge | execute | `job = getMyBackend().run(qc, shots=1000)` |


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