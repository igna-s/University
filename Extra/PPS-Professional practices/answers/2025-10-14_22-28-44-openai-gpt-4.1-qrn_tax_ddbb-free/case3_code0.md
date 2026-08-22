| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import qasm | Deprecation -> The qiskit.qasm module is deprecated and removed | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | qiskit.qasm | from qiskit import qasm2 |
| 9 | circuit1 = qasm.Qasm(data=qasm_str) | Deprecation -> Legacy OpenQASM parser replaced; construct circuit from qasm2 | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | qasm.Qasm | circuit1 = qasm2.loads(qasm_str) |
| 10 | program1 = circuit1.parse() | Deprecation -> parse() removed; use parsed circuit directly | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | Qasm.parse |  |
| 11 | qc1 = program1.get_circuit() | Deprecation -> get_circuit() removed; qasm2.loads returns QuantumCircuit | qrn_tax_ddbb-450ac4cb-0afb-4542-bc25-6847b387ed14 | get_circuit | qc1 = circuit1 |

```python
from qiskit import qasm2
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
circuit1 = qasm2.loads(qasm_str)
qc1 = circuit1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```