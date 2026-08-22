| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | * | Deprecation -> `qiskit.utils.QuantumInstance` removed | `QuantumInstance` | |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | * | Deprecation -> `qiskit.utils.algorithm_globals` removed | `algorithm_globals` | |
| 4 | `from qiskit.opflow import Z, I, X` | * | Deprecation -> `qiskit.opflow` module removed | `qiskit.opflow` | `from qiskit.quantum_info import SparsePauliOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | * | Deprecation -> `qiskit.opflow` operators and expressions removed | `(Z ^ I) + (X ^ X)` | `hamiltonian = SparsePauliOp.from_list([('ZI', 1), ('XX', 1)])` |
| 10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | * | Deprecation -> `qiskit.utils.algorithm_globals` removed | `algorithm_globals.random.random` | `initial_point = np.random.rand(ansatz.num_parameters)` |
| 13 | `quantum_instance = QuantumInstance(` | * | Deprecation -> `qiskit.utils.QuantumInstance` removed | `QuantumInstance` | |
| 16 | `    seed_simulator=algorithm_globals.random_seed,` | * | Deprecation -> `qiskit.utils.algorithm_globals` removed | `algorithm_globals.random_seed` | `    seed_simulator=seed,` |
| 17 | `    seed_transpiler=algorithm_globals.random_seed` | * | Deprecation -> `qiskit.utils.algorithm_globals` removed | `algorithm_globals.random_seed` | `    seed_transpiler=seed` |