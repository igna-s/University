| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> UnitaryGate() function is deprecated | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> ExtensionError() is deprecated | qrn_notax_ddbb--8fa78c41-fe65-4855-a211-6812b683b158 | ExtensionError | `from qiskit.exceptions import ExtensionError` |