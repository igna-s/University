| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 10 | `from qiskit import Aer` | Deprecation -> Importing Aer from qiskit is deprecated | IK | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() is deprecated, use AerSimulator() | IK | Aer.get_backend | `backend = AerSimulator()` |