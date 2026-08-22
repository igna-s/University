| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:--------|:--------:|:--------|:-----------|
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> The Qasm class has been removed in Qiskit 1.0.0 | IK | qiskit.qasm.Qasm | `from qiskit.circuit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm constructor removed | IK | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> parse() method removed | IK | Qasm |  |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> get_circuit() method removed | IK | Qasm |  |

```python
from qiskit.circuit import QuantumCircuit
from utils import getJob, getBackend

qasm_file = "C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```