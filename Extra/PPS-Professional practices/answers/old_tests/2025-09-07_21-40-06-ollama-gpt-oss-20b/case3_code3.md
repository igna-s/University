| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 2 | `from qiskit import qasm2 as qasm` | * | Deprecation -> qiskit.qasm2 module deprecated | qiskit.qasm2 | `from qiskit import qasm` |
| 10 | `qasm_str = qasm.dumps(qc)` | * | Deprecation -> qasm.dumps() function deprecated | qasm.dumps | `qasm_str = qasm.circuit_to_qasm_str(qc)` |
| 11 | `parsed_circuit = qasm.loads(qasm_str)` | * | Deprecation -> qasm.loads() function deprecated | qasm.loads | `parsed_circuit = qasm.qasm_str_to_circuit(qasm_str)` |