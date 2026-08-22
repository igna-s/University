| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | * | Deprecation -> `execute()` function deprecated | `execute` | `from qiskit import QuantumCircuit, Aer` |
| 2 | `from qiskit import qasm2 as qasm` | * | Deprecation -> `qiskit.qasm2` module deprecated | `qiskit.qasm2` | |
| 9 | `qasm_str = qc.qasm()` | * | Deprecation -> `QuantumCircuit.qasm()` method deprecated | `QuantumCircuit.qasm()` | `qasm_str = qc.qasm(formatted=True)` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | * | Deprecation -> `qiskit.qasm.Qasm` class deprecated | `qiskit.qasm.Qasm` | `circuit = QuantumCircuit.from_qasm_str(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | * | Deprecation -> `qiskit.qasm.Qasm.parse()` method deprecated | `qiskit.qasm.Qasm.parse()` | |
| 13 | `circuit = program.get_circuit()` | * | Deprecation -> `qiskit.qasm.Program.get_circuit()` method deprecated | `qiskit.qasm.Program.get_circuit()` | |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | * | Deprecation -> `execute()` function deprecated | `execute` | `job = simulator.run(circuit, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | * | Deprecation -> `Result.get_counts()` method argument changed | `Result.get_counts()` | `counts = result.get_counts(circuit)` |