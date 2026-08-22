| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:---:|:-----|:--------|:----------|:--------|:------------|
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> qasm2 module changed to loads function | IK | qiskit.qasm2 | `from qiskit.qasm2 import loads` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> Qasm class removed | IK | qiskit.qasm2.Qasm | `circuit = loads(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Removed -> obsolete parse method | IK | qiskit.qasm2.Qasm.parse |  |
| 13 | `circuit = program.get_circuit()` | Removed -> obsolete get_circuit method | IK | qiskit.qasm2.Program.get_circuit |  |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> execute expects circuit | IK | execute | `job = execute(circuit, simulator, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Deprecation -> get_counts expects circuit | IK | Result.get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit.qasm2 import loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

circuit = loads(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```