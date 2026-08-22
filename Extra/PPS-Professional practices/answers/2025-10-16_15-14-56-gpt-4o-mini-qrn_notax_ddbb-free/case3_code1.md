| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The qiskit.qasm module is deprecated | qrn_notax_ddbb--e6569a55-d255-4f0b-8b49-1e0efd89380a | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 3 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The Qasm() function is deprecated | qrn_notax_ddbb--910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | Qasm | `circuit2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 4 | `program2 = circuit2.parse()` | Remove -> The parse() function is not available | IK | Qasm |  |
| 5 | `qc2 = program2.get_circuit()` | Remove -> The get_circuit() function is not available | IK | program2 |  |
| 7 | `simulator = getBackend()` | Updated -> Use BasicProvider instead | qrn_notax_ddbb--bdfc0899-dad8-4479-af86-e874c42ed8f4 | getBackend | `from qiskit.providers.basic_provider import BasicProvider\nsimulator = BasicProvider().get_backend("basic_simulator")` |
| 8 | `job = getJob(qc2)` | Updated -> The getJob() function is not available | IK | getJob | `job = simulator.run(qc2)` |
| 9 | `result = job.result()` | Updated -> Job result fetching method is deprecated | IK | result | `result = job.result()` |
| 10 | `counts = result.get_counts()` | Updated -> The get_counts() function is available from results of a QuantumCircuit | IK | result | `counts = result.get_counts(qc2)` |
| 11 | `print(counts)` | | IK | | | 

```python
from qiskit import QuantumCircuit
from qiskit.providers.basic_provider import BasicProvider

qasm_file="C:/qasm_file.qasm"
circuit2 = QuantumCircuit.from_qasm_file(qasm_file)

simulator = BasicProvider().get_backend("basic_simulator")
job = simulator.run(circuit2)
result = job.result()
counts = result.get_counts(circuit2)
print(counts)
```