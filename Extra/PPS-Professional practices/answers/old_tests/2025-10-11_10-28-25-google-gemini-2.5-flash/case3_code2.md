| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module is deprecated. | * | internal | `Aer` | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` function is deprecated. | * | internal | `execute` | (removed, replaced by `backend.run()`) |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is deprecated. | * | internal | `qiskit.qasm2` | (module removed) |
| 9 | `qasm_str = qc.qasm()` | Deprecation -> `QuantumCircuit.qasm()` method without argument is deprecated. | * | internal | `qc.qasm()` | `qasm_str = qc.qasm('qasm2')` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> `qiskit.qasm.Qasm` class is deprecated. | * | internal | `qasm.Qasm` | `qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> `qiskit.qasm.Qasm.parse()` method is deprecated. | * | internal | `qasm_qc.parse()` | (removed) |
| 13 | `circuit = program.get_circuit()` | Deprecation -> `Program.get_circuit()` method is deprecated. | * | internal | `program.get_circuit()` | (removed) |
| 15 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | * | internal | `Aer.get_backend` | `simulator = AerSimulator()` |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> `execute` function is deprecated. | * | internal | `execute` | `job = simulator.run(qasm_qc, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Change -> `Result.get_counts()` no longer requires a circuit argument for single circuit results. | * | internal | `result.get_counts(qasm_qc)` | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm('qasm2')

qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)

simulator = AerSimulator()
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```