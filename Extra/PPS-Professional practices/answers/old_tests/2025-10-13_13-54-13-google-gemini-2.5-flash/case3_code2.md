```markdown
| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qasm2` import alias is deprecated | * | Internal Knowledge | qiskit.qasm2 | `from qiskit.qasm2 import qasm2` |
| 8 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> `qasm.Qasm` class is deprecated | * | Internal Knowledge | qasm.Qasm | `circuit = qasm2(qasm_str)` |
| 9 | `program = qasm_qc.parse()` | Deprecation -> `Program.parse()` method is deprecated | * | Internal Knowledge | qasm_qc.parse | (removed) |
| 10 | `circuit = program.get_circuit()` | Deprecation -> `Program.get_circuit()` method is deprecated | * | Internal Knowledge | program.get_circuit | (removed) |
| 12 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> using `qasm_qc` instead of a `QuantumCircuit` | * | Internal Knowledge | qasm_qc | `job = execute(circuit, simulator, shots=1024)` |
| 14 | `counts = result.get_counts(qasm_qc)` | Deprecation -> passing `qasm_qc` to `get_counts` | * | Internal Knowledge | result.get_counts | `counts = result.get_counts(circuit)` |
```

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit.qasm2 import qasm2

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

circuit = qasm2(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```
