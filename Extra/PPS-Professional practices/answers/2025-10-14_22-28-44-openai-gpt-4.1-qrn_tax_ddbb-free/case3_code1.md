| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit.qasm import Qasm | Deprecation -> The qiskit.qasm module is deprecated and removed, use qiskit.qasm2 or QuantumCircuit.from_qasm_file | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | qiskit.qasm | from qiskit import QuantumCircuit |
| 4 | circuit2 = Qasm(filename=qasm_file) | Deprecation -> Qasm legacy parser removed; use QuantumCircuit.from_qasm_file | qrn_tax_ddbb-76794fac-acfd-4420-83aa-6cfd72bcdb32 | Qasm | circuit2 = QuantumCircuit.from_qasm_file(qasm_file) |
| 5 | program2 = circuit2.parse() | Deprecation -> Qasm legacy parser's parse() removed; QuantumCircuit is already loaded | qrn_tax_ddbb-76794fac-acfd-4420-83aa-6cfd72bcdb32 | Qasm.parse | (remove entirely) |
| 6 | qc2 = program2.get_circuit() | Deprecation -> Qasm legacy parser's program object removed; QuantumCircuit is already loaded | qrn_tax_ddbb-76794fac-acfd-4420-83aa-6cfd72bcdb32 | get_circuit | qc2 = circuit2 |

```python
from qiskit import QuantumCircuit
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
circuit2 = QuantumCircuit.from_qasm_file(qasm_file)
qc2 = circuit2

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```