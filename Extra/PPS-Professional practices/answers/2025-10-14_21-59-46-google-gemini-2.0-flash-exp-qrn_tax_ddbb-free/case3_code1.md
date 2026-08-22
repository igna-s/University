| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Class Qasm is deprecated | qrn_tax_ddbb-ff38182b75a44893be8c291333ffeed1 | qiskit.qasm |  `from qiskit.qasm3 import QASM3Parser` <br>`from qiskit.circuit import QuantumCircuit`<br>`def read_qasm3_file(filename):`<br>`    with open(filename, 'r') as f:`<br>`        qasm3_source = f.read()`<br>`    parser = QASM3Parser()`<br>`    return parser.parse_str(qasm3_source)`<br><br>`# Usage:`<br>`# qasm_file = "C:/qasm_file.qasm"`<br>`# program2 = read_qasm3_file(qasm_file)`<br>`# qc2 = QuantumCircuit.from_parsed_qasm3(program2)` |

```python
from qiskit.qasm3 import QASM3Parser
from qiskit.circuit import QuantumCircuit
from utils import getJob, getBackend

def read_qasm3_file(filename):
    with open(filename, 'r') as f:
        qasm3_source = f.read()
    parser = QASM3Parser()
    return parser.parse_str(qasm3_source)

qasm_file="C:/qasm_file.qasm"
program2 = read_qasm3_file(qasm_file)
qc2 = QuantumCircuit.from_parsed_qasm3(program2)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```