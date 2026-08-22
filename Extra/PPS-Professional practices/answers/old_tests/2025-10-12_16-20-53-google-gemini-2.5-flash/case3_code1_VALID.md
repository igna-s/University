| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> Deprecation of `qiskit.qasm` module | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in `qiskit.qasm` has been deprecated. It will be removed in the Qiskit 1.0.0 release. | * | 3b865a5c-0601-4d2f-8255-3c4db3ac0b8c | Qasm | `circuit2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The qiskit.qasm module which has been deprecated. | * | 902d11f1-10de-40ae-a1e9-2f40e32c600b | parse | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The qiskit.qasm module which has been deprecated. | * | 902d11f1-10de-40ae-a1e9-2f40e32c600b | get_circuit | |


```python
from qiskit.circuit import QuantumCircuit
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