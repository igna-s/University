| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 9d7cce45-a3d8-4d56-aedc-7451f1ff8b84 | qiskit.qasm | `from qiskit.qasm import QASM2Lexer, QASM2Parser` |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> Deprecation of QuantumCircuit.qasm() method | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | d7e9e7b3-38c8-4b1a-b6a3-8cbdaa6227b4 | QuantumCircuit.qasm() | `qasm_str = qc.qasm()` |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> Deprecation of qiskit.converters.ast_to_dag function | 7ee71448-83a6-4ba4-8284-9b29b875ca8f | 7ee71448-83a6-4ba4-8284-9b29b875ca8f | qiskit.converters.ast_to_dag | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |


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