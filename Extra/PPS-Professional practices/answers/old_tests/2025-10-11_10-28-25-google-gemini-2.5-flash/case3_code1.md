| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of qiskit.qasm module | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `from qiskit import qasm2` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Deprecation of qiskit.qasm module | * | d7e9e7b3-38c8-4b1a-b6a3-8cbdaa6227b4 | Qasm | `circuit2 = qasm2.load(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The qiskit.qasm module has been deprecated | * | d7e9e7b3-38c8-4b1a-b6a3-8cbdaa6227b4 | circuit2.parse() | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The qiskit.qasm module has been deprecated | * | d7e9e7b3-38c8-4b1a-b6a3-8cbdaa6227b4 | program2.get_circuit() | |


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