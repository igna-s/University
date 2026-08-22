| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 9 | `from qiskit import Aer` | Deprecation -> The `Aer` module has been deprecated | 02c83a5a-c28d-46c6-acc2-4db931c4c15a | Aer | `from qiskit_aer import Aer` |
| 10 | `backend = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | internal | Aer.get_backend | `backend = AerSimulator()` |
| 17 | `qc.draw(output='mpl')` | Deprecation -> `output` parameter in `QuantumCircuit.draw()` is deprecated. | f346b080-6922-4467-b50a-f11187494f6c | QuantumCircuit.draw | `qc.draw(output='mpl', interactive=True)` |