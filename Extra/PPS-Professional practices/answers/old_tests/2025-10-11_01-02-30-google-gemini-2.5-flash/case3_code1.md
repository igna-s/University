| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. It will be removed in the Qiskit 1.0.0 release. | a03d6cfd-4c92-4523-a77d-3542afe18906 | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The qiskit.converters.ast_to_dag function has been deprecated and will be removed in the Qiskit 1.0.0 release. If you were previously using this, you can instead parse your OpenQASM 2 files into a QuantumCircuit using the QuantumCircuit.from_qasm_file() or QuantumCircuit.from_qasm_str() constructor methods. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The qiskit.converters.ast_to_dag function has been deprecated and will be removed in the Qiskit 1.0.0 release. If you were previously using this, you can instead parse your OpenQASM 2 files into a QuantumCircuit using the QuantumCircuit.from_qasm_file() or QuantumCircuit.from_qasm_str() constructor methods. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | Qasm.parse() | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The qiskit.converters.ast_to_dag function has been deprecated and will be removed in the Qiskit 1.0.0 release. If you were previously using this, you can instead parse your OpenQASM 2 files into a QuantumCircuit using the QuantumCircuit.from_qasm_file() or QuantumCircuit.from_qasm_str() constructor methods. | d3e0c6f3-753f-4ff7-a61d-73446a5621de | program.get_circuit() | |


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