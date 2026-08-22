| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> The qiskit.qasm module is deprecated | a03d6cfd-4c92-4523-a77d-3542afe18906 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> Qiskit’s execute() function is deprecated | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | qiskit.execute | `from qiskit import QuantumCircuit, transpile` |
| 12 | `job = execute(qc, getMyBackend(), shots=1000)` | Deprecation -> Qiskit’s execute() function is deprecated | 0b78d58d-ae5a-415b-aabc-02e0532a0c9e | execute | `new_circuit = transpile(qc, getMyBackend())` |
| 13 | `result = job.result().get_counts(qc)` | Deprecation -> The QuantumCircuit.qasm() method is deprecated | 4bbc9ad5-a04d-4ad1-97e1-83484b7a6eba | get_counts | `result = job.result().get_counts()` |


```python
import os
from datetime import datetime
from qiskit import QuantumCircuit, transpile
import matplotlib.pyplot as plt
from utils import getMyBackend

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure(0, 0)
qc.measure(1, 1)

new_circuit = transpile(qc, getMyBackend())
job = getMyBackend().run(new_circuit, shots=1000)
result = job.result().get_counts()
plt.show()
```