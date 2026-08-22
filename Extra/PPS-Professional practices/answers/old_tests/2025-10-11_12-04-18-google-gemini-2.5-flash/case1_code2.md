| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | [Release Notes](https://docs.quantum.ibm.com/api/qiskit/release-notes/0.46) | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Deprecation of execute() function | bc39cc74-3382-4b55-bc9c-c44558547f03 | [Release Notes](https://docs.quantum.ibm.com/api/qiskit/release-notes/0.46) | execute() | `from qiskit import QuantumCircuit` (and introduce `BackendSampler`) |
| 11 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Deprecation of execute() function | cc6d2843-80cd-4947-9bb4-a8bf5bc7b9f6 | [Release Notes](https://docs.quantum.ibm.com/api/qiskit/release-notes/0.46) | execute() | `sampler = BackendSampler(getMyBackend())` and `job = sampler.run(qc, shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
import matplotlib.pyplot as plt
from utils import getMyBackend
from qiskit.primitives import BackendSampler

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