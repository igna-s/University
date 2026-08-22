| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 1 | `from qiskit import qasm` | * | Deprecation -> `qiskit.qasm` module import deprecated | qiskit.qasm | `from qiskit import QuantumCircuit` |
| 8 | `circuit1 = qasm.Qasm(data=qasm_str)` | * | Deprecation -> `qiskit.qasm.Qasm` class deprecated | qiskit.qasm.Qasm | `qc1 = QuantumCircuit.from_qasm_str(qasm_str)` |
| 9 | `program1 = circuit1.parse()` | * | Deprecation -> `parse()` method of deprecated `qiskit.qasm.Qasm` output | qiskit.qasm.Qasm.parse() | |
| 10 | `qc1 = program1.get_circuit()` | * | Deprecation -> `get_circuit()` method of deprecated `qiskit.qasm.ParsedQASM` object | qiskit.qasm.ParsedQASM.get_circuit() | |