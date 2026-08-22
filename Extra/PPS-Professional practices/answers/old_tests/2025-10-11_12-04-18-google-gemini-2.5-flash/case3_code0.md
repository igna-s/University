| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `from qiskit import qasm2` |
| 12 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 13 | `program1 = circuit1.parse()` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | circuit1.parse() | |
| 14 | `qc1 = program1.get_circuit()` | Deprecation -> Deprecation of qiskit.qasm module | * | internal | program1.get_circuit() | |


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