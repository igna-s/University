| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 1 | `from qiskit.qasm import Qasm` | * | Deprecation -> `qiskit.qasm` module and `Qasm` class are deprecated | `qiskit.qasm.Qasm` | `from qiskit.circuit import QuantumCircuit` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | * | Deprecation -> `Qasm` class constructor is deprecated | `Qasm` | `qc2 = QuantumCircuit.from_qasm_file(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | * | Deprecation -> `Qasm.parse()` method is deprecated | `parse()` | |
| 6 | `qc2 = program2.get_circuit()` | * | Deprecation -> `QasmProgram.get_circuit()` method is deprecated | `get_circuit()` | |