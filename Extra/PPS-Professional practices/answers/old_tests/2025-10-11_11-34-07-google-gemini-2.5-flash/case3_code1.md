| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> `qiskit.qasm` module has been removed. Use `QuantumCircuit.from_qasm_file` instead. | * | internal | qiskit.qasm.Qasm | |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `Qasm` class has been removed. Use `QuantumCircuit.from_qasm_file` for loading QASM files. | * | internal | qiskit.qasm.Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `Qasm` class and its `parse` method have been removed. Use `QuantumCircuit.from_qasm_file` for loading QASM files. | * | internal | Qasm.parse | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `Qasm` class and its `get_circuit` method have been removed. Use `QuantumCircuit.from_qasm_file` for loading QASM files. | * | internal | Qasm.get_circuit | |


```python
from qiskit import QuantumCircuit
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```