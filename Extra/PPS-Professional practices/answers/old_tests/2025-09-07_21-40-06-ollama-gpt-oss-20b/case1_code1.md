| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit import Aer              # type: ignore` | * | Deprecation -> qiskit.Aer module moved to qiskit_aer | Aer | `from qiskit_aer import Aer` |
| 4 | `from qiskit import qasm             # type: ignore` | * | Removal -> qiskit.qasm module removed | qasm | |