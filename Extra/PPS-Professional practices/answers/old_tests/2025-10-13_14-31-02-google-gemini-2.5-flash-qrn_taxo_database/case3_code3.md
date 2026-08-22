| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm` module is deprecated. Use `qiskit.qasm2` instead. (optional) | 14 | ff8d6f94-8ce3-4141-b540-46220def892a | qiskit.qasm2 | `from qiskit.qasm import QASM2Lexer, QASM2Parser` |
| 10 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The `QuantumCircuit.qasm()` method is deprecated. Use `qasm2.dump()` or `qasm2.dumps()` instead. (optional) | 16 | ff8d6f94-8ce3-4141-b540-46220def892a | qasm.dumps | `qasm_str = qc.qasm()` |
| 11 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The `QuantumCircuit.qasm()` method is deprecated. Use `qasm2.dump()` or `qasm2.dumps()` instead. (optional) | 16 | ff8d6f94-8ce3-4141-b540-46220def892a | qasm.loads | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qc.qasm()
parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```