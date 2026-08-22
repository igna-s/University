| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:----:|------|----------|-----------|----------|-------------|
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> `Qasm` class removed in 1.0.0 | IK | `qiskit.qasm.Qasm` | `from qiskit.qasm2 import Qasm2` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Updated -> use `Qasm2` for parsing | IK | `Qasm` | `qasm_obj = Qasm2(filename=qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> `parse()` removed; `Qasm2` auto-parses | IK | `parse` | *remove line* |
| 7 | `qc2 = program2.get_circuit()` | Updated -> replace `get_circuit()` with `circuit` attribute | IK | `get_circuit` | `qc2 = qasm_obj.circuit` |

```python
from qiskit.qasm2 import Qasm2
from utils import getJob, getBackend

qasm_file = "C:/qasm_file.qasm"
qasm_obj = Qasm2(filename=qasm_file)
qc2 = qasm_obj.circuit

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
