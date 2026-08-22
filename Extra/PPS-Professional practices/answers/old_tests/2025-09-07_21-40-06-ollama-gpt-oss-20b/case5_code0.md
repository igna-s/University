| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | * | Deprecation -> `qiskit.extensions` module deprecated | HGate | |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | * | Deprecation -> `qiskit.extensions` module deprecated | XGate | |
| 2 | `from qiskit.extensions import HGate, XGate, Initialize` | * | Deprecation -> `qiskit.extensions` module deprecated | Initialize | |
| 3 | `from qiskit.extensions import Barrier` | * | Deprecation -> `qiskit.extensions` module deprecated | Barrier | |
| 4 | `from qiskit.extensions import UnitaryGate` | * | Deprecation -> `qiskit.extensions` module deprecated | UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 9 | `qc.append(HGate(), [qr[0]])` | * | Deprecation -> Using `qc.append()` for standard gates is less idiomatic (optional) | qc.append(HGate) | `qc.h(qr[0])` |
| 10 | `qc.append(XGate(), [qr[1]])` | * | Deprecation -> Using `qc.append()` for standard gates is less idiomatic (optional) | qc.append(XGate) | `qc.x(qr[1])` |
| 17 | `init_gate = Initialize(psi)` | * | Deprecation -> `Initialize` class instantiation is less idiomatic (optional) | Initialize | |
| 18 | `qc.append(init_gate, [qr[0]])` | * | Deprecation -> Using `qc.append()` for `Initialize` is less idiomatic (optional) | qc.append(init_gate) | `qc.initialize(psi, [qr[0]])` |
| 20 | `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` | * | Deprecation -> Using `qc.append()` for `Barrier` is less idiomatic (optional) | qc.append(Barrier) | `qc.barrier(qr)` |