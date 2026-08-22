| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |  
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |  
| 1 | `    from qiskit.qasm import Qasm` | Deprecation -> Qasm class removed in Qiskit 1.0 | * | internal | qiskit.qasm.Qasm | `from qiskit import QuantumCircuit` |  
| 5 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> Qasm usage replaced by QuantumCircuit.from_qasm_file | * | internal | Qasm usage | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |  
| 6 | `program2 = circuit2.parse()` | Deprecation -> Qasm.parse removed | * | internal | Qasm.parse | # removed |  
| 7 | `qc2 = program2.get_circuit()` | Deprecation -> get_circuit removed | * | internal | Qasm.get_circuit | # removed |  

```python
from qiskit import QuantumCircuit
from utils import getJob, getBackend

qasm_file="C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = getBackend()
job = getJob(qc2)
result = job.result()
counts = result.get_counts()
print(counts)
```
