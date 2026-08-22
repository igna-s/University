| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm.Qasm | `from qiskit.qasm2 import loads` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | Qasm | `with open(qasm_file, "r") as f: circuit_qasm = f.read() # Read the QASM file content program2 = loads(circuit_qasm)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | parse | |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | get_circuit | `qc2 = program2 # program2 is already the QuantumCircuit` |


```python
from utils import getJob, getBackend
from qiskit.qasm2 import loads

qasm_file="C:/qasm_file.qasm"
with open(qasm_file, "r") as f:
    circuit_qasm = f.read()
program2 = loads(circuit_qasm)
qc2 = program2

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```