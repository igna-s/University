| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------- | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Migration -> UnitaryGate moved to qiskit.circuit.library | IK | qiskit.extensions.UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |