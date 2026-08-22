| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_tax_ddbb--14f83328-1859-48be-abd1-0332e05235cc | qiskit.qasm | `from qiskit import qasm2` | 
| 2 | `qasm_str = """..."""` | (optional) | IK | qasm_str | `qasm_str = """..."""` | 
| 3 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> The qasm() function from qiskit.qasm is deprecated | qrn_tax_ddbb--09bdef90-6f6e-4b9d-9be7-c0c45414f961 | qiskit.qasm | `circuit1 = qasm2.Qasm(data=qasm_str)` | 
| 4 | `program1 = circuit1.parse()` | (optional) | IK | program1 | `program1 = circuit1.parse()` | 
| 5 | `qc1 = program1.get_circuit()` | (optional) | IK | qc1 | `qc1 = program1.get_circuit()` |
| 8 | `simulator = getBackend()` | (optional) | IK | simulator | `simulator = getBackend()` | 
| 9 | `job = getJob(qc1)` | (optional) | IK | job | `job = getJob(qc1)` | 
| 10 | `result = job.result()` | (optional) | IK | result | `result = job.result()` |
| 11 | `counts = result.get_counts()` | (optional) | IK | counts | `counts = result.get_counts()` | 
| 12 | `print(counts)` | (optional) | IK | print | `print(counts)` | 

```python
from qiskit import qasm2

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
circuit1 = qasm2.Qasm(data=qasm_str)
program1 = circuit1.parse()
qc1 = program1.get_circuit()

simulator = getBackend()
job = getJob(qc1)
result = job.result()
counts = result.get_counts()
print(counts)
```