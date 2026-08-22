| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit.qasm2 import loads` or `from qiskit.qasm2 import load` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `Qasm` class has been superseded by the `qiskit.qasm2` module | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | Qasm | `with open(qasm_file, "r") as f: qc2 = loads(f.read())` or `qc2 = load(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `Qasm.parse()` method is deprecated | d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | Qasm.parse() | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `program.get_circuit()` method is deprecated | d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | program.get_circuit() | |


```python
from utils import getJob, getBackend
from qiskit.qasm2 import load 

qasm_file="C:/qasm_file.qasm"
qc2 = load(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```