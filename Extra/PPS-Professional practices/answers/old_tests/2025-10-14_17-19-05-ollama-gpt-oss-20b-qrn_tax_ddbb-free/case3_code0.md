
| Line | Code                                              | Scenario                                        | Reference | Artifact                        | Refactoring                                            |
|------|----------------------------------------------------|-------------------------------------------------|-----------|---------------------------------|--------------------------------------------------------|
| 1    | `from qiskit import qasm`                         | Removal -> qiskit.qasm module removed           | IK        | qiskit.qasm                     | `from qiskit.circuit import QuantumCircuit`           |
| 13   | `circuit1 = qasm.Qasm(data=qasm_str)`             | Removal -> qiskit.qasm.Qasm class removed       | IK        | qiskit.qasm.Qasm                 | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)`       |
| 14   | `program1 = circuit1.parse()`                     | Removal -> qiskit.qasm.Qasm.parse method removed| IK        | qiskit.qasm.Qasm.parse           | *(empty)*                                              |
| 15   | `qc1 = program1.get_circuit()`                    | Removal -> get_circuit method removed           | IK        | qiskit.qasm.Qasm.get_circuit      | *(empty)*|

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
