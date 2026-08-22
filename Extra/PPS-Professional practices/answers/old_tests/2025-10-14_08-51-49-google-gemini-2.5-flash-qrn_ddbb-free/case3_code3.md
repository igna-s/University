| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The `qiskit.qasm2` module is deprecated | Internal Knowledge | `qiskit.qasm2` | |
| 10 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The `qiskit.qasm2.dumps()` function is deprecated | Internal Knowledge | `qasm.dumps` | `qasm_str = qc.qasm()` |
| 11 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The `qiskit.qasm2.loads()` function is deprecated | Internal Knowledge | `qasm.loads` | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |


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