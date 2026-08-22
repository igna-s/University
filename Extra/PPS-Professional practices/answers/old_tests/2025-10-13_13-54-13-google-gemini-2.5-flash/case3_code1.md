```markdown
| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Qasm class is deprecated | * | Internal Knowledge | Qasm | `from qiskit.qasm2 import parse_qasm_file` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm constructor is deprecated | * | Internal Knowledge | Qasm constructor | `qc2 = parse_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> parse() method is deprecated | * | Internal Knowledge | parse() |  |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> get_circuit() method is deprecated | * | Internal Knowledge | get_circuit |  |
```

```python
from qiskit.qasm2 import parse_qasm_file
from utils import getJob, getBackend

qasm_file = "C:/qasm_file.qasm"
qc2 = parse_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
