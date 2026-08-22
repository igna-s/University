| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `from qiskit import qasm2` |
| 10 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The qiskit.qasm module is deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qasm.Qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 11 | `program1 = circuit1.parse()` | Deprecation -> The qiskit.qasm module is deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | circuit1.parse() | `program1 = circuit1` |
| 12 | `qc1 = program1.get_circuit()` | Deprecation -> The qiskit.qasm module is deprecated | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | program1.get_circuit() | `qc1 = program1` |


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
circuit1 = qasm2.loads(qasm_str)
program1 = circuit1
qc1 = program1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```