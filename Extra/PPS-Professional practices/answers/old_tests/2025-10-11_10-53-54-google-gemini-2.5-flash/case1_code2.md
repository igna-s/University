| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of qiskit.qasm module | 16 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit import qasm2` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of execute() function | 27 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute() | `from qiskit.transpiler import transpile` |
| 13 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Deprecation of execute() function | 27 | bc39cc74-3382-4b55-bc9c-c44558547f03 | execute() | `job = transpile(qc, getMyBackend()).run(shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit import qasm2
from qiskit.transpiler import transpile
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = transpile(qc, getMyBackend()).run(shots=1000)
result = job.result().get_counts(qc)
plt.show()
```