| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm | `from qiskit import qasm2` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | Qasm | `circuit2 = qasm2.load(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | Qasm.parse() | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. The legacy OpenQASM 2 parser has been superseded by the qiskit.qasm2 module which provides a faster more correct parser for OpenQASM 2. | * | ace97a00-7ee7-4af5-9a34-359da7578661 | program.get_circuit() | |


```python
from qiskit import qasm2
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = qasm2.load(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```