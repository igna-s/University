| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `    from qiskit import qasm` | Deprecation -> qasm module removed | IK | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Migration -> QASM parsing updated | IK | qiskit.qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |

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