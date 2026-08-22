| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm.Qasm` module and class are deprecated. | Internal Knowledge | `qiskit.qasm.Qasm` | `from qiskit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Instantiation of the deprecated `Qasm` class. | Internal Knowledge | `Qasm` | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> Usage of the `parse()` method from the deprecated `Qasm` object. | Internal Knowledge | `circuit2.parse()` | (Removed) |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> Usage of the `get_circuit()` method from the deprecated `Program` object. | Internal Knowledge | `program2.get_circuit()` | (Removed) |


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