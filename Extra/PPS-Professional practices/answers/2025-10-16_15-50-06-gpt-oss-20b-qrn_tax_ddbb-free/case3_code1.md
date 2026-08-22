| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit.qasm import Qasm | Deprec पहचान -> qiskit.qasm module deprecated and will be removed | qrn_tax_ddbb--d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | from qiskit import qasm2 |
| 4 | circuit2 = Qasm(filename=qasm_file) | Deprecation -> legacy OpenQASM 2 parser replaced by qiskit.qasm2 | qrn_tax_ddbb--d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm.Qasm | qc2 = qasm2.load_qasm(qasm_file) |
| 5 | program2 = circuit2.parse() | Deprecation -> legacy OpenQASM 2 parser replaced by qiskit.qasm2 | qrn_tax_ddbb--d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm.Qasm.parse |  |
| 6 | qc2 = program2.get_circuit() | Deprecation -> legacy OpenQASM 2 parser replaced by qiskit.qasm2 | qrn_tax_ddbb--d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm.Qasm.get_circuit |  |

```python
from qiskit import qasm2
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = qasm2.load_qasm(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
