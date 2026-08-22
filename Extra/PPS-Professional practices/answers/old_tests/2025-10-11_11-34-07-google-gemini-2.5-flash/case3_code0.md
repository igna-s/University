| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 11 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 12 | `program1 = circuit1.parse()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | |
| 13 | `qc1 = program1.get_circuit()` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | |


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