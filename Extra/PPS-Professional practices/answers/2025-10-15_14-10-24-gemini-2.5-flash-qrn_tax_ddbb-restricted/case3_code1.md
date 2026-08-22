| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `qiskit.qasm.Qasm` class is deprecated. | d81c6f52-5772-420b-9094-0c9d7d5b64a2 | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `parse()` method of the deprecated `Qasm` class is no longer needed. | d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | parse() | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `get_circuit()` method of the deprecated `Qasm` workflow is no longer needed. | d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | get_circuit() | |


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