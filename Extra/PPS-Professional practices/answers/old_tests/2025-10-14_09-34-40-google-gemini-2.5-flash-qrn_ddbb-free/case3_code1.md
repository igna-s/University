| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> `qiskit.qasm` module is deprecated | qrn_ddbb-c15a | `qiskit.qasm.Qasm` | `from qiskit.qasm2 import load` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> `Qasm` class constructor is deprecated | qrn_ddbb-c15a | `Qasm` | `qc2 = load(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> `parse` method is deprecated | qrn_ddbb-c15a | `parse` | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> `get_circuit` method is deprecated | qrn_ddbb-c15a | `get_circuit` | |


```python
from qiskit.qasm2 import load
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = load(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```