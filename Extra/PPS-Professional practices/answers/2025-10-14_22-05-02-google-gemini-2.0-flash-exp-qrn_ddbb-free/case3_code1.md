| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_ddbb-447a0e5526d441f4a07801d94084c17b | qiskit.qasm | `from qiskit.qasm3 import QASM3Parser` |
| 3 | `qasm_file="C:/qasm_file.qasm"` | Updated -> Using QASM3 to process the file | IK | qasm_file | `qasm_file="C:/qasm_file.qasm"` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The class 'Qasm' is deprecated | qrn_ddbb-4f185b3231584a94a32d7a58611b02c3 | Qasm | `with open(qasm_file, 'r') as f:`\n `    program2 = QASM3Parser().parse(f.read())` |
| 5 | `program2 = circuit2.parse()` | Removal -> The class 'Qasm' does not have attribute parse | qrn_ddbb-9563e92a2124457398938f2716977844 | parse |  |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The class 'Qasm' does not have attribute get_circuit | qrn_ddbb-d238c08881274b4290eedc2564488e92 | get_circuit | `qc2 = program2` |

```python
from qiskit.qasm3 import QASM3Parser
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
with open(qasm_file, 'r') as f:
    program2 = QASM3Parser().parse(f.read())
qc2 = program2

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```