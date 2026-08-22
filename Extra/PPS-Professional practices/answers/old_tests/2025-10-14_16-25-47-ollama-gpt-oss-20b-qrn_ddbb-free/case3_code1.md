| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> Qasm class removed | IK | Qasm | `from qiskit.circuit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm constructor removed | IK | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecated -> parse no longer needed | IK | parse | *(remove line)* |
| 7 | `qc2 = program2.get_circuit()` | Deprecated -> get_circuit no longer needed | IK | get_circuit | *(remove line)* |

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