| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `from qiskit import Aer` | Deprecation -> Aer module import deprecated | IK | qiskit.Aer | `from qiskit.providers.aer import AerSimulator` |
| 9 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> Aer.get_backend() method is deprecated | IK | Aer.get_backend | `backend = AerSimulator()` |
| 12 | `job = getJob(qc, backend, 1000).result().get_counts(qc)` | Update -> Replace custom getJob usage with backend.run and get_counts (mandatory) | IK | getJob | `job = backend.run(qc, shots=1000).result().get_counts()` |