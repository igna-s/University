| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 4 | `from qiskit import extensions as ext` | * | Deprecation -> qiskit.extensions module deprecated | qiskit.extensions | |
| 19 | `qc.prepare_state(psi, [qr[0]])` | * | Deprecation -> QuantumCircuit.prepare_state() method deprecated | QuantumCircuit.prepare_state | `qc.initialize(psi, [qr[0]])` |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | * | Deprecation -> Barrier from qiskit.extensions deprecated | qiskit.extensions.Barrier | `qc.barrier([qr[0], qr[1], qr[2]])` |