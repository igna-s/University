Line | Code | Scenario | Reference | Artifact | Refactoring
--- | --- | --- | --- | --- | ---
1 | `from qiskit import Aer` | `Deprecation -> Import from qiskit.providers.aer deprecated` | `IK` | `Aer` | `from qiskit_aer import Aer`
2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | `Deprecation -> algorithm_globals usage deprecated` | `IK` | `algorithm_globals` | `from qiskit.utils import QuantumInstance`
4 | `from qiskit.opflow import Z, I, X` | `Deprecation -> qiskit.opflow module removed` | `IK` | `qiskit.opflow` | `from qiskit.quantum_info import PauliOp`
7 | `hamiltonian = (Z ^ I) + (X ^ X)` | `Deprecation -> opflow operators Z, I, X deprecated` | `IK` | `Z, I, X` | `hamiltonian = PauliOp('ZI') + PauliOp('XX')`
10 | `initial_point = algorithm_globals.random.random(ansatz.num_parameters)` | `Deprecation -> algorithm_globals.random usage deprecated` | `IK` | `algorithm_globals.random` | `np.random.seed(42); initial_point = np.random.rand(ansatz.num_parameters)`
16 | `seed_simulator=algorithm_globals.random_seed` | `Deprecation -> algorithm_globals.random_seed usage deprecated` | `IK` | `algorithm_globals.random_seed` | `seed_simulator=42`
17 | `seed_transpiler=algorithm_globals.random_seed` | `Deprecation -> algorithm_globals.random_seed usage deprecated` | `IK` | `algorithm_globals.random_seed` | `seed_transpiler=42`