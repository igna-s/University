| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Aer.get_backend() is deprecated | Internal Knowledge | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The execute() function is deprecated | Internal Knowledge | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The qiskit.qasm2 module is deprecated | qrn_tax_ddbb-931c | qasm2 | `from qiskit.qasm import loads` |
| 7 | `qasm_str = qc.qasm()` | Updated -> Specify the QASM version for qc.qasm() | qrn_tax_ddbb-d43c | qasm() | `qasm_str = qc.qasm(version=2)` |
| 9 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> qiskit.qasm.Qasm class for parsing QASM is deprecated | qrn_tax_ddbb-50b4 | qasm.Qasm | `circuit_from_qasm = loads(qasm_str)` |
| 10 | `program = qasm_qc.parse()` | Deprecation -> qiskit.qasm.Qasm.parse() is deprecated | qrn_tax_ddbb-50b4 | parse() | |
| 11 | `circuit = program.get_circuit()` | Deprecation -> qiskit.qasm.program.get_circuit() is deprecated | qrn_tax_ddbb-50b4 | get_circuit() | |
| 13 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend() is deprecated | Internal Knowledge | Aer.get_backend | `simulator = AerSimulator()` |
| 14 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The execute() function is deprecated | Internal Knowledge | execute | `job = simulator.run(circuit_from_qasm, shots=1024)` |
| 16 | `counts = result.get_counts(qasm_qc)` | Deprecation -> Argument to get_counts() should be a QuantumCircuit object | Internal Knowledge | get_counts | `counts = result.get_counts(circuit_from_qasm)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.qasm import loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm(version=2)

circuit_from_qasm = loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(circuit_from_qasm, shots=1024)
result = job.result()
counts = result.get_counts(circuit_from_qasm)
print(counts)
```