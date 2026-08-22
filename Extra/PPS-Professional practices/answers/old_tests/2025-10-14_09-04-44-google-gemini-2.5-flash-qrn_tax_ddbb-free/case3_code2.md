| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` has been moved to `qiskit_aer` and `execute` is deprecated. | Internal Knowledge | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute()` function is deprecated. | Internal Knowledge | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm2` module for parsing is deprecated. | Internal Knowledge | qiskit.qasm2 | `from qiskit.qasm2 import dumps, loads` |
| 7 | `qasm_str = qc.qasm()` | Deprecation -> The `QuantumCircuit.qasm()` method is deprecated. | Internal Knowledge | QuantumCircuit.qasm() | `qasm_str = dumps(qc)` |
| 8 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> The `qiskit.qasm2.Qasm` class for parsing is deprecated. | Internal Knowledge | qasm.Qasm | `parsed_circuit = loads(qasm_str)` |
| 9 | `program = qasm_qc.parse()` | Deprecation -> The old QASM parsing mechanism is deprecated. | Internal Knowledge | qasm_qc.parse() | |
| 10 | `circuit = program.get_circuit()` | Deprecation -> The old QASM parsing mechanism is deprecated. | Internal Knowledge | program.get_circuit() | `circuit = parsed_circuit` |
| 12 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | Internal Knowledge | Aer.get_backend | `simulator = AerSimulator()` |
| 13 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The `execute()` function is deprecated and the argument `qasm_qc` is of a deprecated type. | Internal Knowledge | execute | `job = simulator.run(circuit, shots=1024)` |
| 16 | `counts = result.get_counts(qasm_qc)` | Deprecation -> The argument `qasm_qc` is of a deprecated type. | Internal Knowledge | get_counts | `counts = result.get_counts(circuit)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.qasm2 import dumps, loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = dumps(qc)

parsed_circuit = loads(qasm_str)
circuit = parsed_circuit

simulator = AerSimulator()
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```