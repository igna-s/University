| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The QuantumCircuit.qasm() method is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit | Replace `qc.qasm()` with `qasm.dump(qc)` | 
| 5 | `qasm_str = qc.qasm()` | Deprecation -> The QuantumCircuit.qasm() method is deprecated | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit | Replace with `qasm_str = qasm.dumps(qc)` | 
| 9 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Updated -> Use new Qasm constructor | qrn_notax_ddbb-508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qiskit.qasm2 | Replace with `qasm_qc = qasm.Qasm(data=qasm_str)` (remains unchanged in 1.0.0) |
| 11 | `job = execute(qasm_qc, simulator, shots=1024)` | Updated -> The execute() function usage remains the same | IK | qiskit | Replace with `job = execute(qasm_qc, backend, shots=1024)` | 

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm.dumps(qc)

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

backend = Aer.get_backend('qasm_simulator')
job = execute(qasm_qc, backend, shots=1024)
result = job.result()
counts = result.get_counts(qasm_qc)
print(counts)
```