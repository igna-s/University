| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> qiskit.qasm.Qasm class deprecated, use qiskit.qasm2 or QuantumCircuit.from_qasm_str | qrn_tax_ddbb--364bba83-0d97-41a3-8d46-211c6c6c7f94 | qiskit.qasm.Qasm | `from qiskit import QuantumCircuit` |
| 10 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> qiskit.qasm.Qasm class use deprecated, use QuantumCircuit.from_qasm_str | qrn_tax_ddbb--364bba83-0d97-41a3-8d46-211c6c6c7f94 | qiskit.qasm.Qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 11 | `program1 = circuit1.parse()` | Deprecation -> parse() method usage is no longer valid, replaced by QuantumCircuit construction | qrn_tax_ddbb--f850b1f5-bd30-49fc-88dc-1a0f0ba05c11 | qiskit.qasm.Qasm.parse | _Remove line_ |
| 12 | `qc1 = program1.get_circuit()` | Deprecation -> get_circuit() method usage is obsolete due to direct QuantumCircuit generation | qrn_tax_ddbb--e87c1ca9-440a-4d81-8002-53b7f94cc39f | Qasm.get_circuit | _Remove line_ |

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