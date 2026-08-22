| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:---:|:-----|:---------|:----------|:--------|:------------|
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | `qiskit.qasm.Qasm` | `from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `qiskit.qasm` module is deprecated. | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | `Qasm` | Removed (replaced by `QuantumCircuit.from_qasm_file`) |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `qiskit.qasm` module is deprecated. | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | `Qasm.parse` | Removed |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `qiskit.qasm` module is deprecated. | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | `program2.get_circuit` | Removed |

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
