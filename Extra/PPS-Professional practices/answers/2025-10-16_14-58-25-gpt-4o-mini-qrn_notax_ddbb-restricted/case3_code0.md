| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit import qasm2` |
| 6 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecated -> Qasm() constructor is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit.qasm | `circuit1 = qasm2.loads(qasm_str)` |
| 7 | `program1 = circuit1.parse()` | Deprecated -> parse() method is deprecated | qrn_notax_ddbb-e6569a55-d255-4f0b-8b49-1e0efd89380a | qiskit.qasm | `program1 = circuit1}` |
| 8 | `qc1 = program1.get_circuit()` | Deprecated -> get_circuit() method is deprecated | qrn_notax_ddbb-e6569a55-d255-4f0b-8b49-1e0efd89380a | program1 | `qc1 = circuit1` |
| 10 | `simulator = getBackend()` | Update -> The getBackend() function is deprecated | qrn_notax_ddbb-a4289ec8-8488-4fa4-99f8-c46141a06471 | getBackend | `from qiskit.providers.fake_provider import GenericBackendV2` |
| 11 | `job = getJob(qc1)` | Update -> The getJob() function is deprecated | qrn_notax_ddbb-a4289ec8-8488-4fa4-99f8-c46141a06471 | getJob | `job = backend.run(qc1)` |


```python
from qiskit import qasm2
from qiskit.providers.fake_provider import GenericBackendV2

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

backend = GenericBackendV2()
job = backend.run(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```