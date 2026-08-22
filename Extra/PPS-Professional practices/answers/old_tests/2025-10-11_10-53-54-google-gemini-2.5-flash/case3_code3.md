| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> Deprecation of qiskit.qasm module | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | qiskit.qasm | `from qiskit.qasm import QASM2Lexer, QASM2Parser, dumps, loads` |
| 10 | `qasm_str = qasm.dumps(qc)` | Deprecation -> Deprecation of QuantumCircuit.qasm() method | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | QuantumCircuit.qasm() | `qasm_str = dumps(qc)` |
| 11 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> Deprecation of QuantumCircuit.qasm() method | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | 0e323991-f76c-4e8b-9bf4-0a8f1455f99d | QuantumCircuit.qasm() | `parsed_circuit = loads(qasm_str)` |


```python
from qiskit import QuantumCircuit
from qiskit.qasm import QASM2Lexer, QASM2Parser, dumps, loads
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = dumps(qc)
parsed_circuit = loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```