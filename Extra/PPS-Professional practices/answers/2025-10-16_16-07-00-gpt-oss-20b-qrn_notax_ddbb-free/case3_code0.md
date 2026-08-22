| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module removed | IK | qiskit.qasm | `from qiskit import qasm2` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Migration -> use new qasm2 parser | IK | qiskit.qasm.Qasm | `circuit1 = qiskit.qasm2.load_qasm(qasm_str)` |
| 14 | `program1 = circuit1.parse()` | Removed method parse | IK | qiskit.qasm.Qasm |  |
| 15 | `qc1 = program1.get_circuit()` | Removed method get_circuit | IK | qiskit.qasm.Qasm |  |

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
circuit1 = qiskit.qasm2.load_qasm(qasm_str)
qc1 = circuit1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```