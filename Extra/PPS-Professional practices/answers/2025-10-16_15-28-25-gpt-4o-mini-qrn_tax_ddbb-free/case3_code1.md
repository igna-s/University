| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import qasm2` |
| 3 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The Qasm class is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | Qasm | `circuit2 = qasm2.loads(qasm_file)` |
| 4 | `program2 = circuit2.parse()` | Deprecation -> parse method of Qasm is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | Qasm | `program2 = qasm2.loads(circuit2)` |

```python
from qiskit import qasm2
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
circuit2 = qasm2.loads(qasm_file)
program2 = qasm2.loads(circuit2)
qc2 = program2.get_circuit()

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```