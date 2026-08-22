| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit.qasm2 import QASM2Parser` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | Qasm | `with open(qasm_file, "r") as f: qc2 = QASM2Parser(f.read()).parse()` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | circuit2.parse | |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | program2.get_circuit | |


```python
from qiskit.qasm2 import QASM2Parser
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
with open(qasm_file, "r") as f:
    qc2 = QASM2Parser(f.read()).parse()

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```