| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | `qiskit.qasm` | `from qiskit.circuit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `Qasm` class from `qiskit.qasm` is deprecated | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | `Qasm` | `QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Deprecation -> The `.parse()` method of the deprecated `Qasm` object is no longer available | * | internal | `Qasm.parse()` | |
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> The `.get_circuit()` method on the result of a deprecated `Qasm` object is no longer available | * | internal | `program.get_circuit()` | |

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