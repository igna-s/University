| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm | `from qiskit import qasm2` |
| 7 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | qiskit.qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 8 | `program1 = circuit1.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | qiskit.qasm | |
| 9 | `qc1 = program1.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | qiskit.qasm | |


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