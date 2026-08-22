| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The qasm module is deprecated. | qrn_tax_ddbb-a2c5a83c96b3a83a4f0c6c148546566c | qasm | `from qiskit.qasm3 import QASM3Parser` |
| 10 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The qasm module is deprecated. | qrn_tax_ddbb-a2c5a83c96b3a83a4f0c6c148546566c | qasm | `parser = QASM3Parser()` |
| 11 | `program1 = circuit1.parse()` | Deprecation -> The qasm module is deprecated. | qrn_tax_ddbb-a2c5a83c96b3a83a4f0c6c148546566c | qasm | `program1 = parser.parse_str(qasm_str)` |

```python
from qiskit.qasm3 import QASM3Parser
from utils import getJob, getBackend

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
parser = QASM3Parser()
program1 = parser.parse_str(qasm_str)
qc1 = program1.get_circuit()

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```