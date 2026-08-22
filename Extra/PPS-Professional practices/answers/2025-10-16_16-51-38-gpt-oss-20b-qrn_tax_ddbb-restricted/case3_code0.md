| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import qasm2` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> qiskit.qasm.Qasm class deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm.Qasm | `qc1 = qiskit.qasm2.parse_qasm(qasm_str)` |
| 14 | `program1 = circuit1.parse()` | Removed (legacy parser) | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm.Qasm |  |
| 15 | `qc1 = program1.get_circuit()` | Removed (legacy circuit retrieval) | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm.Qasm |  |

```python
from qiskit import qasm2
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

qc1 = qasm2.parse_qasm(qasm_str)

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```