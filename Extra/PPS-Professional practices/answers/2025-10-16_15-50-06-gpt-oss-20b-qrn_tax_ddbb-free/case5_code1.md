| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> extensions module removed | IK | extensions | Remove import line |
| 21 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> Barrier gate via extensions module is deprecated | IK | Barrier | Replace with `qc.barrier(qr)` |