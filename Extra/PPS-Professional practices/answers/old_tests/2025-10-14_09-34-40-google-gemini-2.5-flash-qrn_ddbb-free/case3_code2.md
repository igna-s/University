| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module is deprecated and moved | Internal Knowledge | Aer | `from qiskit.providers.basic_provider import BasicSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute` function is deprecated | Internal Knowledge | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is removed | Internal Knowledge | qiskit.qasm2 | |
| 8 | `qasm_str = qc.qasm()` | Changed Default Behavior (optional) -> `QuantumCircuit.qasm()` now defaults to QASM 3.0 | Internal Knowledge | QuantumCircuit.qasm() | `qasm_str = qc.qasm(version=2)` |
| 10 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> `qiskit.qasm2.Qasm` class is removed | Internal Knowledge | qasm.Qasm | `circuit = QuantumCircuit.from_qasm_str(qasm_str)` |
| 11 | `program = qasm_qc.parse()` | Deprecation -> `qiskit.qasm2.Qasm.parse()` method is removed | Internal Knowledge | qasm_qc.parse() | |
| 12 | `circuit = program.get_circuit()` | Deprecation -> `qiskit.qasm2.Program.get_circuit()` method is removed | Internal Knowledge | program.get_circuit() | |
| 14 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend()` function is deprecated | Internal Knowledge | Aer.get_backend | `simulator = BasicSimulator()` |
| 15 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> `execute` function is deprecated | Internal Knowledge | execute | `job = simulator.run(circuit, shots=1024)` |
| 17 | `counts = result.get_counts(qasm_qc)` | Deprecation -> Argument for `result.get_counts()` no longer accepts `qiskit.qasm2` objects | Internal Knowledge | qasm_qc | `counts = result.get_counts(circuit)` |


```python
from qiskit import QuantumCircuit
from qiskit.providers.basic_provider import BasicSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm(version=2)

circuit = QuantumCircuit.from_qasm_str(qasm_str)

simulator = BasicSimulator()
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```