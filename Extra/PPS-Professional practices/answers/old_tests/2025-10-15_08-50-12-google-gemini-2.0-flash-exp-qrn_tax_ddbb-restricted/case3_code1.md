| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated. | qrn_tax_ddbb-e29f185d-756f-41d1-a394-6b516679a442 | qiskit.qasm | `from qiskit.qasm3 import Qasm3Parser`\n`from qiskit.circuit import QuantumCircuit` |
| 3 | `qasm_file="C:/qasm_file.qasm"` | New functionality -> Use Qasm3Parser to parse a QASM 3 file and create a QuantumCircuit object. | qrn_tax_ddbb-05940257-a836-4576-9d6d-963574118613 | qiskit.qasm | `parser = Qasm3Parser()`\n`qc2 = parser.parse_file(qasm_file)` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The qiskit.qasm module is deprecated. | qrn_tax_ddbb-e29f185d-756f-41d1-a394-6b516679a442 | qiskit.qasm | `parser = Qasm3Parser()`\n`qc2 = parser.parse_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Removal ->  The Qasm class and its associated methods have been removed. | qrn_tax_ddbb-d199ca2f-4c83-434a-b913-945c396e059c | qasm.parse |  |
| 6 | `qc2 = program2.get_circuit()` | Removal ->  The Qasm class and its associated methods have been removed. | qrn_tax_ddbb-d199ca2f-4c83-434a-b913-945c396e059c | qasm.parse |  |

```python
from qiskit.qasm3 import Qasm3Parser
from qiskit.circuit import QuantumCircuit
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
parser = Qasm3Parser()
qc2 = parser.parse_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```