| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `Aer` module is deprecated | 4 | 3e95df91-e1c5-4340-8243-daa95d502170 | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `execute()` function is deprecated | 5 | 8878ac1a-c067-4924-a116-185016f37a9c | execute | `from qiskit import transpile` |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> The legacy OpenQASM 2 parser module `qiskit.qasm` has been deprecated | 6 | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | |
| 10 | `qasm_str = qc.qasm()` | Deprecation -> `QuantumCircuit.qasm()` method is deprecated | 7 | 4a85ead9-680f-49b5-b1dc-982401b98f61 | QuantumCircuit.qasm() | `qasm_str = qasm2.dumps(qc)` |
| 12 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> The legacy OpenQASM 2 parser module `qiskit.qasm` has been deprecated | 6 | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | `qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)` |
| 13 | `program = qasm_qc.parse()` | Deprecation -> The legacy OpenQASM 2 parser module `qiskit.qasm` has been deprecated | 6 | 2edcf1ef-edac-448b-be69-fe31c5179872 | qiskit.qasm | |
| 14 | `circuit = program.get_circuit()` | Deprecation -> The `ast_to_dag` function has been deprecated | 6 | a1be9ccb-ff98-44ba-a1b5-57e100241a55 | ast_to_dag | |
| 16 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated | 4 | d80bef70-77b8-42bd-b127-0e057f4a268d | Aer.get_backend | `simulator = AerSimulator()` |
| 17 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> `execute()` function is deprecated | 5 | 8878ac1a-c067-4924-a116-185016f37a9c | execute | `transpiled_qc = transpile(qasm_qc, simulator)`<br>`job = simulator.run(transpiled_qc, shots=1024)` |
| 19 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts(exp_idx)` is deprecated | 12 | f7bd1861-358a-4281-bb81-7ff574c97f70 | result.get_counts | `counts = result.get_counts()` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit import qasm2
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm2.dumps(qc)

qasm_qc = QuantumCircuit.from_qasm_str(qasm_str)

simulator = AerSimulator()
transpiled_qc = transpile(qasm_qc, simulator)
job = simulator.run(transpiled_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```