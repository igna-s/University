| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 4 | `from qiskit import extensions as ext` | Deprecation -> `qiskit.extensions` module removed | 01d78ad7-f654-464a-85d0-9980d9929281 | qiskit.extensions | |
| 16 | `qc.append(ext.Barrier(3), [qr[0], qr[1], qr[2]])` | Deprecation -> `qiskit.extensions` module removed | 01d78ad7-f654-464a-85d0-9980d9929281 | ext.Barrier | `qc.barrier()` |