| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 4 | `from qiskit.qasm import Qasm` | Deprecation -> `qasm` module removed | 19a12660-3c5c-4020-8c6c-1a30c587c37f | internal | qiskit.qasm |  |
| 5 | `from qiskit.algorithms import VQE` | Deprecation -> `VQE` moved to `qiskit.algorithms.minimum_eigensolvers` | 29e7c10a-4d9b-470a-9f82-24762d030749 | internal | qiskit.algorithms.VQE | `from qiskit.algorithms.minimum_eigensolvers import VQE` |
| 7 | `from qiskit import qasm2 as qasm` | Deprecation -> `qasm` module removed | 19a12660-3c5c-4020-8c6c-1a30c587c37f | internal | qiskit.qasm2 |  |