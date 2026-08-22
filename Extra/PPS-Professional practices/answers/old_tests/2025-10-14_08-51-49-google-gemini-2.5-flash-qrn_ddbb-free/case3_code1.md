| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module and `Qasm` class are deprecated and removed. | Internal Knowledge | `qiskit.qasm.Qasm` | `from qiskit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `Qasm` class constructor for loading QASM files is deprecated. | Internal Knowledge | `Qasm` | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> The `parse()` method of the `Qasm` object is deprecated. | Internal Knowledge | `parse` | |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> The `get_circuit()` method is deprecated. | Internal Knowledge | `get_circuit` | |


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