| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit.qasm import Qasm | Deprecation -> The Qasm class and qiskit.qasm module have been removed | qrn_ddbb-ffb99035edd84f96b047a43703b98faf | qiskit.qasm.Qasm | Replace Qasm parsing with QuantumCircuit.from_qasm_file(qasm_file) |
| 5 | circuit2 = Qasm(filename=qasm_file) | Deprecation -> The Qasm class and qiskit.qasm module have been removed | qrn_ddbb-ffb99035edd84f96b047a43703b98faf | qiskit.qasm.Qasm | quantum_circuit_obj = QuantumCircuit.from_qasm_file(qasm_file) |
| 6 | program2 = circuit2.parse() | Deprecation -> The Qasm class and qiskit.qasm module have been removed | qrn_ddbb-ffb99035edd84f96b047a43703b98faf | qiskit.qasm.Qasm |  |
| 7 | qc2 = program2.get_circuit() | Deprecation -> The Qasm class and qiskit.qasm module have been removed | qrn_ddbb-ffb99035edd84f96b047a43703b98faf | qiskit.qasm.Qasm |  |

```python  
from utils import getJob, getBackend
from qiskit import QuantumCircuit

qasm_file="C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```