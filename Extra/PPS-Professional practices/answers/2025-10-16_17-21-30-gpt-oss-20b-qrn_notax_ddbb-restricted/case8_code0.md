| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `    from qiskit import Aer` | Deprecation -> qiskit.Aer import deprecated | 4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 4 | `from qiskit.opflow import Z, I, X` | Deprecation -> qiskit.opflow import deprecated | IK | qiskit.opflow | `from qiskit.quantum_info import Pauli, PauliSumOp` |
| 7 | `hamiltonian = (Z ^ I) + (X ^ X)` | Updated -> opflow expression replaced by PauliSumOp | IK | PauliSumOp | `hamiltonian = PauliSumOp.from_list([('ZI', 1), ('XX', 1)])` |
| 12 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> Aer.get_backend deprecated | 4194776d-c578-4b79-8dc6-9c5e286bc808 | Aer.get_backend | `backend = AerSimulator()` |