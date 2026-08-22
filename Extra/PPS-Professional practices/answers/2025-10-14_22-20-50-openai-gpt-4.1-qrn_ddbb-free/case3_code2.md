| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | from qiskit import QuantumCircuit, Aer, execute | Import update -> Importing simulators (Aer) from qiskit is deprecated in 1.0.0 | qrn_ddbb-c915299a-1e49-44d7-ae87-a431d3dd5a95 | Aer | from qiskit_aer import Aer |
| 2 | from qiskit import qasm2 as qasm | Import update -> qasm2 is still available, but usage adapted in new style | IK | qasm2 | from qiskit.qasm2 import dumps, loads |
| 7 | qasm_str = qc.qasm() | Deprecation -> QuantumCircuit.qasm() deprecated and removed | qrn_ddbb-18e49d39-25cd-41a4-8e0e-2906dea4fc9f | QuantumCircuit.qasm() | qasm_str = dumps(qc) |
| 8 | qasm_qc = qasm.Qasm(data=qasm_str) | API change -> Legacy Qasm parser replaced by new loader | IK | qasm.Qasm | qasm_qc = loads(qasm_str) |
| 9 | program = qasm_qc.parse() | API change -> Legacy Qasm parser replaced by new loader | IK | qasm_qc.parse |   |
| 10 | circuit = program.get_circuit() | API change -> New loader returns circuit directly | IK | program.get_circuit | circuit = qasm_qc | 
| 12 | simulator = Aer.get_backend('qasm_simulator') | API update -> Aer is now imported from qiskit_aer | qrn_ddbb-c915299a-1e49-44d7-ae87-a431d3dd5a95 | Aer.get_backend |   |
| 13 | job = execute(qasm_qc, simulator, shots=1024) | API change -> execute may require QuantumCircuit object not parser instance | IK | execute | job = execute(circuit, simulator, shots=1024) |
| 15 | counts = result.get_counts(qasm_qc) | API update -> get_counts should be called with circuit object | IK | get_counts | counts = result.get_counts(circuit) |



```python
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
from qiskit.qasm2 import dumps, loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = dumps(qc)

qasm_qc = loads(qasm_str)
circuit = qasm_qc

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```