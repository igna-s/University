| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` function is deprecated | qrn_notax_ddbb--6c63296a-b5e2-442c-bbbf-cd2a7c2ec0e7 | execute | Remove all usage of `execute`; use circuit.run or backend.run |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qasm2` module handling has changed | qrn_notax_ddbb--aabdd963-2e6f-4042-bdf9-986f8ca7e57e | qasm2 | Use `from qiskit.qasm2 import loads` to parse QASM, remove Qasm class usage |
| 7 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() method deprecated | qrn_notax_ddbb--28cf65fe-bf9d-4e35-9c2b-083c7e4a98a7 | QuantumCircuit.qasm | Instead, use `qc.qasm_qobj()` or directly serialize if appropriate |
| 9 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecated -> `Qasm` class construction is no longer used | qrn_notax_ddbb--aabdd963-2e6f-4042-bdf9-986f8ca7e57e | qasm.Qasm | Use `loads(qasm_str)` to obtain a QuantumCircuit from QASM string |
| 10 | `program = qasm_qc.parse()` | Deprecated -> Qasm.parse() removed in favor of direct parsing | qrn_notax_ddbb--aabdd963-2e6f-4042-bdf9-986f8ca7e57e | qasm.Qasm.parse | Use result of `loads(qasm_str)` directly as a circuit |
| 11 | `circuit = program.get_circuit()` | Deprecated -> get_circuit() method is removed | qrn_notax_ddbb--aabdd963-2e6f-4042-bdf9-986f8ca7e57e | program.get_circuit | Expect `loads(qasm_str)` to return a QuantumCircuit directly |
| 13 | `simulator = Aer.get_backend('qasm_simulator')` | Update -> Aer provider has moved to qiskit.providers.aer | qrn_notax_ddbb--444dfe7c-9c76-43b6-bc44-232f2a765d4b | Aer.get_backend | `from qiskit.providers.aer import Aer` |
| 14 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> execute() function is deprecated | qrn_notax_ddbb--6c63296a-b5e2-442c-bbbf-cd2a7c2ec0e7 | execute | Use `simulator.run(circuit, shots=1024)` |
| 16 | `counts = result.get_counts(qasm_qc)` | Updated -> Pass QuantumCircuit or result as argument to get_counts | IK | result.get_counts | Use `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit
from qiskit.qasm2 import loads
from qiskit.providers.aer import Aer

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()
circuit = loads(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```