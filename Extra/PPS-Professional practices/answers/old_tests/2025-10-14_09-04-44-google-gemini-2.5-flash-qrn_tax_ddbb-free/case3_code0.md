| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The `qiskit.qasm` module is deprecated and removed | Internal Knowledge | qiskit.qasm | |
| 8 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The `qiskit.qasm.Qasm` class is deprecated and removed | Internal Knowledge | qasm.Qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 9 | `program1 = circuit1.parse()` | Deprecation -> The `parse()` method of `qiskit.qasm.Qasm` is deprecated and removed | Internal Knowledge | circuit1.parse() | |
| 10 | `qc1 = program1.get_circuit()` | Deprecation -> The `get_circuit()` method of `qiskit.qasm.QasmProgram` is deprecated and removed | Internal Knowledge | program1.get_circuit() | |


```python
from qiskit.circuit import QuantumCircuit
from utils import getJob, getBackend

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
qc1 = QuantumCircuit.from_qasm_str(qasm_str)

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```