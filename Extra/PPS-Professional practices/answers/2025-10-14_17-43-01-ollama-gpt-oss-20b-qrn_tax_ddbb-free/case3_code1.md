| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm class is deprecated | qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 6 | `program2 = circuit2.parse()` | Structural change -> Qasm.parse is removed | qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | Qasm.parse | `(removed)` |
| 7 | `qc2 = program2.get_circuit()` | Structural change -> get_circuit is removed | qrn_tax_ddbb-002bb3d5-8c9b-4e4e-997d-9404592460f6 | Program.get_circuit | `(removed)` |

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
