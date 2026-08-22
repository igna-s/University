| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> qiskit.qasm.Qasm is deprecated and removed | qrn_tax_ddbb--41eafae2-8a21-4a0e-904e-6a21ac7eefd6 | qiskit.qasm.Qasm | `from qiskit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> qiskit.qasm.Qasm class usage is removed, use QuantumCircuit.from_qasm_file | qrn_tax_ddbb--41eafae2-8a21-4a0e-904e-6a21ac7eefd6 | qiskit.qasm.Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Breaking API -> Qasm().parse() no longer used, replaced by QuantumCircuit.from_qasm_file | qrn_tax_ddbb--41eafae2-8a21-4a0e-904e-6a21ac7eefd6 | qiskit.qasm.Qasm | *(remove, integrated in previous line)* |
| 6 | `qc2 = program2.get_circuit()` | Breaking API -> Qasm().parse().get_circuit() no longer used, replaced by QuantumCircuit.from_qasm_file | qrn_tax_ddbb--41eafae2-8a21-4a0e-904e-6a21ac7eefd6 | qiskit.qasm.Qasm | *(remove, integrated in line 4)* |

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