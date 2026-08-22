| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `from qiskit import qasm2` |
| 12 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 13 | `program1 = circuit1.parse()` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | circuit1.parse() | |
| 14 | `qc1 = program1.get_circuit()` | Deprecation -> Deprecation of qiskit.qasm module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | program1.get_circuit() | |


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