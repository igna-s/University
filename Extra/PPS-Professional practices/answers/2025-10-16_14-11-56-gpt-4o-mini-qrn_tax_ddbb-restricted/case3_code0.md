| Line | Code | Scenario | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :-------: | :------- | :---------- |  
| 1 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb-14b11a6f-b2ca-44f1-8633-034d855abbd4 | qiskit.qasm | `from qiskit import qasm2` |  
| 2 | `qasm_str = """` |  | IK |  |  |  
| 8 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> qasm.Qasm class is deprecated | qrn_tax_ddbb-d5bc1bb4-7acd-47c5-be94-ef19074cbdcc | qiskit.qasm | `circuit1 = QuantumCircuit.from_qasm_str(qasm_str)` |  
| 10 | `getBackend()` | Structural change -> BasicAer replaced with BasicProvider | qrn_tax_ddbb-09db4543-63a6-47dd-9cd7-097a6f9fe1a8 | qiskit.providers.basic_provider | `from qiskit.providers.basic_provider import BasicProvider\nsimulator = BasicProvider().get_backend("basic_simulator")` |  
| 12 | `result = job.result()` | No change needed | IK |  |  |  
| 13 | `counts = result.get_counts()` | No change needed | IK |  |  |  
| 14 | `print(counts)` | No change needed | IK |  |  |  

```python
from qiskit import qasm2
from utils import getJob
from qiskit.providers.basic_provider import BasicProvider

qasm_str = """
OPENQASM 2.0;
include "qelib1.inc";
qreg q[2];
creg c[2];
h q[0];
cx q[0], q[1];
measure q -> c;
"""
circuit1 = QuantumCircuit.from_qasm_str(qasm_str)
job = getJob(circuit1)
result = job.result()
counts = result.get_counts()
print(counts)
```