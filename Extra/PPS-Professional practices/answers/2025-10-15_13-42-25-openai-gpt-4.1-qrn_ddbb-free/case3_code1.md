| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm.Qasm has been removed | IK | qiskit.qasm.Qasm | Use Qiskit QuantumCircuit.from_qasm_file(qasm_file) instead |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Removal -> Qasm initialization removed | IK | qiskit.qasm.Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Removal -> Qasm .parse() method removed | IK | qiskit.qasm.Qasm.parse | Remove, handled by QuantumCircuit.from_qasm_file |
| 6 | `qc2 = program2.get_circuit()` | Removal -> Qasm .get_circuit() method removed | IK | qiskit.qasm.Qasm.get_circuit | Remove, handled by QuantumCircuit.from_qasm_file |

```python
from qiskit import QuantumCircuit
from utils import getJob, getBackend

qasm_file = "C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```