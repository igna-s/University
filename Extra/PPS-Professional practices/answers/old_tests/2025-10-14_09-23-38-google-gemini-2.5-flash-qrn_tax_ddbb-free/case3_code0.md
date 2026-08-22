| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The `qiskit.qasm` module has been deprecated | Internal Knowledge | qiskit.qasm | `from qiskit.qasm2 import loads` |
| 10 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> `qiskit.qasm.Qasm` has been deprecated | Internal Knowledge | qasm.Qasm | `circuit1 = loads(qasm_str)` |
| 11 | `program1 = circuit1.parse()` | Deprecation -> `qiskit.qasm.Qasm.parse` has been deprecated | Internal Knowledge | circuit1.parse | |
| 12 | `qc1 = program1.get_circuit()` | Deprecation -> `qiskit.qasm.Qasm.get_circuit` has been deprecated | Internal Knowledge | program1.get_circuit | |


```python
from qiskit.qasm2 import loads
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
qc1 = loads(qasm_str)

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```