| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:--------|:---------|:---------|:-----------|
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> qasm.Qasm class is removed in Qiskit 1.0.0 | IK | qasm.Qasm | `circuit = qasm.load(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> parse() method on qasm.Qasm removed | IK | Qasm.parse |  |
| 13 | `circuit = program.get_circuit()` | Deprecation -> get_circuit() removed | IK | Program.get_circuit |  |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Updated -> execute expects a circuit, not qasm object | IK | execute | `job = execute(circuit, simulator, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Updated -> get_counts expects a circuit | IK | Result.get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

circuit = qasm.load(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```