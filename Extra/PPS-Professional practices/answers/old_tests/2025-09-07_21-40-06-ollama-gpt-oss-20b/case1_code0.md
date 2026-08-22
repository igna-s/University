| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 4 | `from qiskit.qasm import Qasm` | * | Deprecation -> `qiskit.qasm` module removed | `qiskit.qasm.Qasm` | Remove import; use `QuantumCircuit.from_qasm_str()` or `QuantumCircuit.from_qasm_file()` |
| 5 | `from qiskit.algorithms import VQE` | * | Deprecation -> `qiskit.algorithms` module deprecated, `VQE` moved | `qiskit.algorithms.VQE` | `from qiskit.algorithms.minimum_eigensolvers import VQE` |