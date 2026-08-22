| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit.qasm import QASMInterpreter` |
| 10 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Deprecation of qiskit.qasm module | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qasm.Qasm | `circuit1 = QASMInterpreter().load(qasm_str)` |
| 11 | `program1 = circuit1.parse()` | Deprecation -> Deprecation of qiskit.qasm module | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | circuit1.parse() | `program1 = circuit1` |
| 12 | `qc1 = program1.get_circuit()` | Deprecation -> Deprecation of qiskit.qasm module | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | program1.get_circuit() | `qc1 = program1` |


```python
from utils import getJob, getBackend
from qiskit.qasm import QASMInterpreter

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
circuit1 = QASMInterpreter().load(qasm_str)
program1 = circuit1
qc1 = program1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```