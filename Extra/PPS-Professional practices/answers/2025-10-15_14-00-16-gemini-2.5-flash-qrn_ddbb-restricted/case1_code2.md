| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The function execute() is deprecated. | IK | execute | `from qiskit.utils.run_circuits import run_circuit` |
| 13 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> The function execute() is deprecated. | IK | execute | `job = run_circuit(qc, getMyBackend(), shots=1000)` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit
from qiskit.utils.run_circuits import run_circuit
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

job = run_circuit(qc, getMyBackend(), shots=1000)
result = job.result().get_counts(qc)
plt.show()
```