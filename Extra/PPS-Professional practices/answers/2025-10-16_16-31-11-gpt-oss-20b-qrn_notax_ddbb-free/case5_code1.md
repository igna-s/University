| Line | Code | Scenario | Reference | Artifact | Refactoring |
|:--:|:---|:-------|:-------:|:-------|:-----------|
| 4 | `from qiskit import extensions as ext` | Deprecation -> `qiskit.extensions` module is deprecated | IK | extensions | Remove this import; use `qc.barrier` or import `BarrierGate` from `qiskit.circuit.library` |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `ext.Barrier` is deprecated | IK | Barrier | Replace with `qc.barrier([qr[0], qr[1], qr[2]])` |