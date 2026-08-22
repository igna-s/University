| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit import QuantumCircuit, qasm, execute` | Deprecation -> qiskit.qasm module deprecated | IK | qiskit.qasm | `from qiskit import QuantumCircuit, execute` |