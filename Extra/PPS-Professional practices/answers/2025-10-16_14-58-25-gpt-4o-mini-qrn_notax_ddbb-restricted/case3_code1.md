| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_notax_ddbb-910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The Qasm class is deprecated | qrn_notax_ddbb-e6569a55-d255-4f0b-8b49-1e0efd89380a | Qasm | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecated -> QASM parsing method is removed | qrn_notax_ddbb-e6569a55-d255-4f0b-8b49-1e0efd89380a | circuit2 |  |
| 6 | `qc2 = program2.get_circuit()` | Deprecated -> QASM parsing method is removed | qrn_notax_ddbb-e6569a55-d255-4f0b-8b49-1e0efd89380a | program2 |  |
| 8 | `simulator = getBackend()` | Updated -> Use from qiskit.providers.basic_provider to replace getBackend() | qrn_notax_ddbb-9c5ff30f-89b3-477d-8e94-7d231d6ab6bd | getBackend | `from qiskit.providers.basic_provider import BasicProvider; backend = BasicProvider().get_backend('basic_simulator')` |
| 9 | `job = getJob(qc2)` | Deprecated -> The getJob() function is deprecated | qrn_notax_ddbb-7dcaf104-d552-4d87-994a-c7691846d9a9 | getJob | `job = backend.run(qc2)` |
| 10 | `result = job.result()` | Updated -> job.result() is replaced | IK | job | `result = job` |
| 11 | `counts = result.get_counts()` | Updated -> result.get_counts() is replaced | IK | result | `counts = result` |
| 12 | `print(counts)` | Updated -> print format might require update | IK | counts | `print(counts)` |

```python
from qiskit import QuantumCircuit
from qiskit.providers.basic_provider import BasicProvider

qasm_file = "C:/qasm_file.qasm"
qc2 = QuantumCircuit.from_qasm_file(qasm_file)

backend = BasicProvider().get_backend('basic_simulator')
job = backend.run(qc2)
result = job
counts = result
print(counts)
```