| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Qiskit’s execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | qiskit.execute | |
| 12 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Qiskit’s execute() function is deprecated. This function served as a high-level wrapper around transpiling a circuit with some transpile options and running it on a backend with some run options. To do the same thing, you can explicitly use the transpile() function (with appropriate transpile options) followed by backend.run() (with appropriate run options). | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `from qiskit.primitives import BackendSampler\njob = BackendSampler(getMyBackend()).run(qc)` |


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

from qiskit.primitives import BackendSampler
job = BackendSampler(getMyBackend()).run(qc)
result = job.result().get_counts(qc)
plt.show()
```