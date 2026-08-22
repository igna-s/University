| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The qasm module is deprecated and will be removed in a future release. | qrn_ddbb-fd97b915677b93a807b8a86350fa9947 | qasm | `from qiskit.qasm3 import QASM3Parser` |
| 12 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> Class Qasm is deprecated | qrn_ddbb-b0a0d3491483a20b4857f8062f93ca0a | qasm | `circuit1 = QASM3Parser.parse(qasm_str)` |
| 13 | `program1 = circuit1.parse()` | Removal -> `QuantumCircuit.parse()` is not used anymore. | qrn_ddbb-6e3697c1f0de4a3d63f55a94086de9a7 | parse |  |
| 14 | `qc1 = program1.get_circuit()` | Removal -> `QuantumCircuit.get_circuit()` is not used anymore. | qrn_ddbb-87f85a7632c4572a7cf62354a959ce74 | get_circuit |  |

```python
from qiskit.qasm3 import QASM3Parser
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
circuit1 = QASM3Parser.parse(qasm_str)
qc1 = circuit1

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```