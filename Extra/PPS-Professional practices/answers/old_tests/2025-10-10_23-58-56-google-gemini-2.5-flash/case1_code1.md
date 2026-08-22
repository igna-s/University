| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import Aer              # type: ignore` | Deprecation -> The `qiskit.Aer` module has been moved to `qiskit_aer`. | internal | `qiskit.Aer` | `from qiskit_aer import AerSimulator` |
| 4 | `from qiskit import qasm             # type: ignore` | Deprecation -> The `qiskit.qasm` module is no longer available as a top-level import. | internal | `qiskit.qasm` | |