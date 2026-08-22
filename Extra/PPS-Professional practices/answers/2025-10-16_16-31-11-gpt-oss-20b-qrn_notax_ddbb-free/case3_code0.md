| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> `qiskit.qasm` module removed | IK | qiskit.qasm | `from qiskit import qasm2` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> `qasm.Qasm` constructor removed | IK | qiskit.qasm.Qasm | `qc1 = qasm2.loads(qasm_str)` |
| 14 | `program1 = circuit1.parse()` | Removed method after QASM parser refactor | IK | qasm.Qasm | *remove* |
| 15 | `qc1 = program1.get_circuit()` | Removed method after QASM parser refactor | IK | program1.get_circuit | *remove* |

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
qc1 = qasm2.loads(qasm_str)

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```