| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.test.mock import FakeVigo` | Updated -> FakeVigo import path changed | IK | FakeVigo | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Updated -> ReferenceCircuits import path changed | IK | ReferenceCircuits | `from qiskit.circuit.library.reference_circuits import ReferenceCircuits` |