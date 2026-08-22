| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is removed | * | internal | qiskit.qasm2 | |
| 11 | `qasm_str = qasm.dumps(qc)` | Deprecation -> `qiskit.qasm2.dumps()` is removed, use `QuantumCircuit.qasm()` | * | internal | qasm.dumps | `qasm_str = qc.qasm()` |
| 12 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> `qiskit.qasm2.loads()` is removed, use `QuantumCircuit.from_qasm_str()` | * | internal | qasm.loads | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |


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