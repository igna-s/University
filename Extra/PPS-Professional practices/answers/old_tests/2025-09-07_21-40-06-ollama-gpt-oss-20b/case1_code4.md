| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 10 | `from qiskit import Aer` | * | Modernization -> qiskit.Aer import can be replaced with qiskit_aer specific import | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | * | Modernization -> Aer.get_backend() replaced by direct AerSimulator instantiation | Aer.get_backend | `backend = AerSimulator()` |