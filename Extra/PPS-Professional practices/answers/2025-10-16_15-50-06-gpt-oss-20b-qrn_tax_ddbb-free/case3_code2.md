| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `    from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Importing from qiskit.providers.aer is deprecated | qrn_tax_ddbb--084696d9-2c75-437a-8e84-96506e6766aa | Aer | `from qiskit import QuantumCircuit, execute\nfrom qiskit_aer import AerSimulator` |
| 11 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend is deprecated | qrn_tax_ddbb--084696d9-2c75-437a-8e84-96506e6766aa | Aer.get_backend | `backend = AerSimulator()` |
| 12 | `job = execute(qasm_qc, simulator, shots=1024)` | Migration -> Use QuantumCircuit for execution (optional) | IK | execute | `job = execute(qc, backend, shots=1024)` |
| 14 | `counts = result.get_counts(qasm_qc)` | Migration -> Use qc for get_counts | IK | result.get_counts | `counts = result.get_counts(qc)` |