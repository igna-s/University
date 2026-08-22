| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Qiskit’s execute() function is deprecated. | * | 8878ac1a-c067-4924-a116-185016f37a9c | qiskit.execute | `from qiskit import QuantumCircuit` |
| 12 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Qiskit’s execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | * | 8878ac1a-c067-4924-a116-185016f37a9c | execute | `job = getMyBackend().run(qc, shots=1000)` |


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

backend = getMyBackend()
job = backend.run(qc, shots=1000)
result = job.result().get_counts(qc)
plt.show()
```