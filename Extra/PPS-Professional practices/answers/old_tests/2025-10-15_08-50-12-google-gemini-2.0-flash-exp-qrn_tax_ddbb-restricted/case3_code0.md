| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The `qasm` module is deprecated and will be removed in a future release. | qrn_tax_ddbb-b7a9c925-5c8c-4022-b6f6-74184d182351 | qasm | `from qiskit.qasm3 import QASM3Parser` |
| 12 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Use the QASM3Parser or QASM2File parser  | qrn_tax_ddbb-2991e137-c54b-4f42-85a0-74098664f7bd | qasm.Qasm | `circuit1 = QASM3Parser().parse_str(qasm_str)` |

```python
from utils import getJob, getBackend
from qiskit.qasm3 import QASM3Parser

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
circuit1 = QASM3Parser().parse_str(qasm_str)
program1 = circuit1.get_circuit()
qc1 = program1.get_circuit()

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```