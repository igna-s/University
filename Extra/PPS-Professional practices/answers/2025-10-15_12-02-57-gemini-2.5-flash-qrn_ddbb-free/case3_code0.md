| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in qiskit.qasm has been deprecated. | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit.circuit import QuantumCircuit` |
| 9 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The qiskit.qasm module has been deprecated. | qrn_notax_ddbb--e6569a55-d255-4f0b-8b49-1e0efd89380a | qasm.Qasm | `QuantumCircuit.from_qasm_str(qasm_str)` |
| 10 | `program1 = circuit1.parse()` | Deprecation -> The qiskit.qasm module has been deprecated. | qrn_notax_ddbb--e6569a55-d255-4f0b-8b49-1e0efd89380a | .parse() | |
| 11 | `qc1 = program1.get_circuit()` | Deprecation -> The qiskit.qasm module has been deprecated. | qrn_notax_ddbb--e6569a55-d255-4f0b-8b49-1e0efd89380a | .get_circuit() | |


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