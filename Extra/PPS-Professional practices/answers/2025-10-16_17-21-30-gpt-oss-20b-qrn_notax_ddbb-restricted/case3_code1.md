| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `import qiskit.qasm2 as qasm2` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm class usage is deprecated | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | Qasm | `qc2 = qasm2.load(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> parse() method from Qasm is deprecated | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | Qasm.parse | `# Removed, use qasm2.load` |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> get_circuit() method from program is deprecated | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | Program.get_circuit | `# Removed, use qasm2.load` |

```python
import qiskit.qasm2 as qasm2
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = qasm2.load(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
