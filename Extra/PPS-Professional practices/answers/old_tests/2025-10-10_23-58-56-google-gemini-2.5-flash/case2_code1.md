| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.opflow import PauliSumOp` | Deprecation -> The `qiskit.opflow` module is deprecated | internal | qiskit.opflow | `from qiskit.quantum_info import SparsePauliOp` |
| 3 | `from qiskit.primitives import BackendEstimator` | Deprecation -> `BackendEstimator` is deprecated | internal | BackendEstimator | `from qiskit.primitives import Estimator` |
| 13 | `H1 = PauliSumOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` | Deprecation -> `PauliSumOp` is deprecated | internal | PauliSumOp | `H1 = SparsePauliOp.from_list([("II", 1), ("IZ", 2), ("XI", 3)])` |
| 17 | `estimator = BackendEstimator(` | Deprecation -> `BackendEstimator` is deprecated | internal | BackendEstimator | `estimator = Estimator()` |
| 18 | `backend=backend,` | Deprecation -> `backend` argument removed from `Estimator` constructor | internal | backend | |
| 19 | `options={"shots": 1024}  # Configurar shots aquí` | Deprecation -> `options` for `shots` removed from `Estimator` constructor | internal | options | |
| 23 | `job = estimator.run([psi1], [H1], [theta1])` | Change -> `backend` and `shots` options should be passed to the `run` method | internal | run | `job = estimator.run([psi1], [H1], [theta1], backend=backend, shots=1024)` |