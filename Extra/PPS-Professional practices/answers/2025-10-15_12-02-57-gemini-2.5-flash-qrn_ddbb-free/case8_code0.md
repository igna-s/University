| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import Aer` | Deprecation -> Importing from `qiskit.Aer` is deprecated | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer | `from qiskit_aer import AerSimulator` |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `qiskit.utils.QuantumInstance` is deprecated | IK | QuantumInstance | |
| 2 | `from qiskit.utils import QuantumInstance, algorithm_globals` | Deprecation -> `qiskit.utils.algorithm_globals` is deprecated | IK | algorithm_globals | `from qiskit.utils import algorithm_globals` has no direct replacement in Qiskit 1.0. For random number generation, use Python's `random` module or NumPy's `numpy.random`. |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> `qiskit.opflow` is deprecated | IK | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 13 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated | qrn_notax_ddbb--548acfe8-db26-45b7-ab5c-c637c63ee4b0 | Aer.get_backend | `backend = AerSimulator()` |
| 14 | `quantum_instance = QuantumInstance(` | Deprecation -> `QuantumInstance` is deprecated | IK | QuantumInstance | `sampler = Sampler()` or `estimator = Estimator()` |
| 16 | `seed_simulator=algorithm_globals.random_seed,` | Deprecation -> `algorithm_globals` is deprecated | IK | algorithm_globals.random_seed | `seed_simulator=seed` |
| 17 | `seed_transpiler=algorithm_globals.random_seed` | Deprecation -> `algorithm_globals` is deprecated | IK | algorithm_globals.random_seed | `seed_transpiler=seed` |