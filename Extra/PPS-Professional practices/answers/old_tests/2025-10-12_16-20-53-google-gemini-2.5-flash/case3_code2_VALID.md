| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> qiskit.Aer object deprecated | 4 | bb13d578-c8e9-44dd-8431-861cea75d5de | Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` function deprecated | * | Internal Knowledge | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> qiskit.qasm module deprecated | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `from qiskit.qasm import QASMString, QASMFile` |
| 9 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() method deprecated | 16 | 3c189cb9-1315-4402-b141-a88a25a253f2 | QuantumCircuit.qasm() | `qasm2.dumps(qc)` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> qiskit.qasm module deprecated | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | qiskit.qasm | `qasm_qc = QASMString(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> qiskit.qasm module deprecated | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | Qasm.parse() | `program = qasm_qc.get_circuit()` |
| 13 | `circuit = program.get_circuit()` | Deprecation -> qiskit.qasm module deprecated | 14 | 3c189cb9-1315-4402-b141-a88a25a253f2 | Program.get_circuit() | `circuit = program` |
| 15 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> `execute` function deprecated | * | Internal Knowledge | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 17 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts()` method with circuit argument deprecated | * | Internal Knowledge | get_counts(qasm_qc) | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.qasm import QASMString

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = QASMString(qasm_str)
program = qasm_qc.get_circuit()
circuit = program

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```