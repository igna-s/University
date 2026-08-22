| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `qiskit.qasm` module is deprecated | 14 | ace97a00-7ee7-4af5-9a34-359da7578661 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The `execute()` function is deprecated | * | 7d9abf43-8af9-474a-8d5b-a64db8f90c8a | qiskit.execute | `from qiskit.primitives import BackendSampler` |
| 11 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> The `execute()` function is deprecated | * | 7d9abf43-8af9-474a-8d5b-a64db8f90c8a | execute | `sampler = BackendSampler(getMyBackend())`<br>`job = sampler.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from qiskit.primitives import BackendSampler
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

sampler = BackendSampler(getMyBackend())
job = sampler.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```