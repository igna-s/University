| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module (legacy OpenQASM 2 parser) is deprecated and will be removed | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 7 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation/Removal -> qiskit.qasm.Qasm class is deprecated and will be removed | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm.Qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 8 | `program1 = circuit1.parse()` | Deprecation/Removal -> Legacy OpenQASM 2 parsing via qiskit.qasm.Qasm.parse() is deprecated and will be removed | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm.Qasm.parse | (remove, handled by QuantumCircuit.from_qasm_str) |
| 9 | `qc1 = program1.get_circuit()` | Deprecation/Removal -> Legacy OpenQASM 2 circuit retrieval is deprecated with removal of .get_circuit() method | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | get_circuit | (remove, handled by QuantumCircuit.from_qasm_str) |

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