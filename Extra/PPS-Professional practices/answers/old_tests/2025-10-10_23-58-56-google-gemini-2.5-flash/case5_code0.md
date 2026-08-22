| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | Deprecation -> `qiskit.extensions` module is deprecated | internal | qiskit.extensions | `from qiskit.circuit.library import HGate, XGate, Initialize` |
| 3 | `from qiskit.extensions import Barrier` | Deprecation -> `qiskit.extensions` module is deprecated | internal | qiskit.extensions | `from qiskit.circuit.library import Barrier` |
| 4 | `from qiskit.extensions import UnitaryGate` | Deprecation -> `qiskit.extensions` module is deprecated | internal | qiskit.extensions | `from qiskit.circuit.library import UnitaryGate` |
| 12 | `custom_gate = UnitaryGate(custom_matrix, label="Custom")` | Deprecation -> `UnitaryGate` no longer accepts `label` as a constructor argument | internal | UnitaryGate | `custom_gate = UnitaryGate(custom_matrix).annotate_defines("Custom")` |
| 15 | `init_gate = Initialize(psi)` | Deprecation -> `Initialize` no longer accepts `params` as a constructor argument | internal | Initialize | `init_gate = Initialize(psi).to_gate()` |
| 18 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `Barrier` no longer accepts `num_qubits` as a constructor argument | internal | Barrier | `qc.barrier(3)` |