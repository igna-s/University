| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> `qasm.Qasm` class is deprecated | IK | qasm.Qasm | `qasm_parser = qasm.Qasm2()` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> `qasm_qc.parse()` is deprecated | IK | qasm.Qasm.parse | `circuit = qasm_parser.parse(qasm_str)` |
| 13 | `circuit = program.get_circuit()` | Deprecated -> `program.get_circuit()` no longer needed | IK | program.get_circuit |  |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> executing `qasm_qc` object is not supported | IK | execute | `job = execute(circuit, simulator, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts()` with `qasm_qc` is deprecated | IK | result.get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_parser = qasm.Qasm2()
circuit = qasm_parser.parse(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```
