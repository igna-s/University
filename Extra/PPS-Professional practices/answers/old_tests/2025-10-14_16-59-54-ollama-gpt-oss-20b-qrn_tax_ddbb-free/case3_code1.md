| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:---------|:----------|:--------|:-----------|
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated (removed in 1.0.0) | IK | qiskit.qasm | `    from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm constructor is removed | IK | Qasm class | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Removed in refactoring | IK | Qasm parser | removed |
| 6 | `qc2 = program2.get_circuit()` | Removed in refactoring | IK | Qasm parser | removed |

```python
    from qiskit.circuit import QuantumCircuit
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
