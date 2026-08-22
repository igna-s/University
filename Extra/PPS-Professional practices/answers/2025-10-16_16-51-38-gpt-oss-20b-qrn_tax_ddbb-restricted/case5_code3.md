| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> UnitaryGate moved to qiskit.circuit.library | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> ExtensionError moved to qiskit.exceptions | qrn_tax_ddbb-0ef4f925-2e1f-4821-a64d-9edcfaacc1c0 | ExtensionError | `from qiskit.exceptions import ExtensionError` |