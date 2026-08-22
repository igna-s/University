| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 1 | from qiskit import qasm | Deprecation → qiskit.qasm module deprecated, use qiskit.qasm2 | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | from qiskit import qasm2 |
| 13 | circuit1 = qasm.Qasm(data=qasm_str) | Deprecation → Legacy OpenQASM 2 parser deprecated, use qiskit.qasm2 | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm.Qasm | qc1 = qasm2.loads(qasm_str) |

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
