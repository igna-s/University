| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions` is deprecated | qrn_tax_ddbb-684a2999-1393-460c-b99d-f4403ddc4774 | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 4 | `from qiskit.extensions import Barrier` | Deprecation -> `qiskit.extensions` is deprecated | qrn_tax_ddbb-684a2999-1393-460c-b99d-f4403ddc4774 | qiskit.extensions | `from qiskit.circuit import Barrier` |
| 5 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `qiskit.extensions` is deprecated | qrn_tax_ddbb-684a2999-1393-460c-b99d-f4403ddc4774 | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
