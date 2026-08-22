| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 7 | `from qiskit import Aer` | * | Deprecation -> Aer module moved to qiskit_aer | qiskit.Aer | `from qiskit_aer import Aer` |
| 9 | `from qiskit import execute` | * | Deprecation -> execute function deprecated, use backend.run() instead | qiskit.execute | |
| 10 | `job = execute(qc, backend, shots=1000)` | * | Deprecation -> execute function deprecated, use backend.run() instead | execute() | `job = backend.run(qc, shots=1000)` |
| 13 | `from qiskit.algorithms import VQE` | * | Deprecation -> VQE moved to qiskit.algorithms.minimum_eigensolvers | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 15 | `from qiskit import SPSA` | * | Deprecation -> SPSA moved to qiskit.algorithms.optimizers | qiskit.SPSA | `from qiskit.algorithms.optimizers import SPSA` |