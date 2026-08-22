| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit import qasm2` |
| 11 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The qiskit.qasm module has been deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | qasm.Qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 12 | `program1 = circuit1.parse()` | Deprecation -> The qiskit.qasm module has been deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | circuit1.parse | |
| 13 | `qc1 = program1.get_circuit()` | Deprecation -> The qiskit.qasm module has been deprecated | f24d40d4-9a98-4431-85f5-3e6f98fee373 | program1.get_circuit | `qc1 = circuit1` |


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
qc1 = circuit1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```