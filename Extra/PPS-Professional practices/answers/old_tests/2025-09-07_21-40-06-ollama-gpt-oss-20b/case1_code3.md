| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | * | Deprecation -> qiskit.execute() function deprecated | execute | Remove `execute` from import statement |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | * | Migration -> qiskit.qasm module import path changed | qasm | Remove `qasm` from import statement if not used |