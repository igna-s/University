| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import UnitaryGate` | Deprecation -> The `qiskit.extensions` module is deprecated. | internal | `qiskit.extensions` | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | Deprecation -> The `qiskit.extensions.exceptions` module is deprecated. | internal | `qiskit.extensions.exceptions` | `from qiskit.exceptions import QiskitError` |
| 10 | `raise ExtensionError("La matriz debe ser cuadrada")` | Deprecation -> The `ExtensionError` exception is deprecated. | internal | `ExtensionError` | `raise QiskitError("La matriz debe ser cuadrada")` |
| 15 | `except ExtensionError as e:` | Deprecation -> The `ExtensionError` exception is deprecated. | internal | `ExtensionError` | `except QiskitError as e:` |