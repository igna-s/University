| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `execute()` function is deprecated. | 7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> `Aer` object is deprecated. | 4194776d-c578-4b79-8dc6-9c5e286bc808 | Aer | `from qiskit_aer import Aer` |
| 3 | `from qiskit import QuantumCircuit, execute, Aer, qasm` | Deprecation -> The legacy OpenQASM 2 parser module previously present in `qiskit.qasm` has been deprecated. | 910c7d9a-1fa2-4f70-9635-3ff5a9209f24 | qasm | |
| 11 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated. | 4194776d-c578-4b79-8dc6-9c5e286bc808 | Aer.get_backend | `backend = AerSimulator()` |