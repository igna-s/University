| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The qiskit.qasm2 module has been superseded by the qiskit.qasm module, which provides a faster, more correct parser for OpenQASM 2 | * | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm2 | `from qiskit.qasm import QASM2Lexer, QASM2Parser` |
| 9 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The qasm2.dumps() function is deprecated and will be removed in Qiskit 1.0.0. The QuantumCircuit.qasm() method should be used instead. | * | 4a85ead9-680f-49b5-b1dc-982401b98f61 | qasm.dumps | `qasm_str = qc.qasm()` |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The qasm2.loads() function is deprecated and will be removed in Qiskit 1.0.0. The QuantumCircuit.from_qasm_str() constructor method should be used instead. | * | a1be9ccb-ff98-44ba-a1b5-57e100241a55 | qasm.loads | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |


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