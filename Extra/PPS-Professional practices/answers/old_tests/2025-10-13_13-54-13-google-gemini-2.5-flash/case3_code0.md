```markdown
| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `    from qiskit import qasm` | Deprecation -> qasm module import deprecated | * | Internal Knowledge | qiskit.qasm | Remove and replace with `from qiskit import QuantumCircuit` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Migration -> QASM parsing replaced by QuantumCircuit.from_qasm_str | * | Internal Knowledge | qasm.Qasm | Replace with `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 14 | `program1 = circuit1.parse()` | Deprecation -> parse() method removed | * | Internal Knowledge | parse() | Remove |
| 15 | `qc1 = program1.get_circuit()` | Deprecation -> get_circuit() method removed | * | Internal Knowledge | get_circuit() | Remove |
```

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
