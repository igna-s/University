| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import qasm` | Deprecation -> The legacy OpenQASM 2 parser module qiskit.qasm is deprecated and will be removed | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 8 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Instantiating qasm.Qasm is deprecated, use QuantumCircuit.from_qasm_str instead | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | qasm.Qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 9 | `program1 = circuit1.parse()` | Removal -> parse() will be removed as qiskit.qasm is deprecated | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | parse() |  |
| 10 | `qc1 = program1.get_circuit()` | Removal -> get_circuit() will be removed as qiskit.qasm is deprecated | qrn_ddbb-1ff0d2a4-05b0-4eb6-87ae-fe09d97a40e6 | get_circuit() |  |

```python
from qiskit import QuantumCircuit
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