| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> `qiskit.extensions` module is deprecated and should be removed | IK | extensions | Remove this import; use submodules directly. |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `qiskit.extensions.Barrier` is deprecated; use `qiskit.circuit.Barrier` | IK | Barrier | Replace with `qc.append(Barrier(3), [qr[0], qr[1], qr[2]])` and import `Barrier` from `qiskit.circuit`. |