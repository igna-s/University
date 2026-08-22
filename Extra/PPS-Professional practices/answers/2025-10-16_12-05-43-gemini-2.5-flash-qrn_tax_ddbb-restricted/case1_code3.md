| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The `qiskit.execute` function is deprecated. `qiskit.Aer` is deprecated and will stop working in Qiskit 1.0. | IK | execute, Aer | `from qiskit import QuantumCircuit` <br> `from qiskit_aer import AerSimulator` |
| 12 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | 084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend | `backend = AerSimulator()` |
| 13 | `job = getJob(qc, backend, 1000)` | Deprecation -> `qiskit.execute` function is deprecated. | IK | getJob | `job = backend.run(qc, shots=1000)` |