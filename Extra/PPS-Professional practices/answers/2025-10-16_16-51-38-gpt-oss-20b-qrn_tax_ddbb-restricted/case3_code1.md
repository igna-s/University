| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module deprecated | qrn_tax_ddbb-d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm class / legacy parser deprecated | qrn_tax_ddbb-d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> parse() method removed |  |  |  |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> get_circuit() removed |  |  |  |

```python
from qiskit import QuantumCircuit
from utils import getJob, getBackend

qasm_file = "C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
