| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> `execute()` function is deprecated. It has been moved to a method of the `QuantumCircuit` class | IK | execute | `job = qc.run(backend, shots=1024)` |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> `qiskit.providers.fake_provider` module has been migrated to the `qiskit_ibm_runtime` Python package. | qrn_tax_ddbb-27ebf47d-f549-4a4b-ad7c-72ec480eb99d | FakeVigo | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> `qiskit.test.reference_circuits` module is deprecated. | IK | ReferenceCircuits | `from qiskit.circuit.library import BellState` |
| 4 | `from qiskit.test.base import BaseTestCase` | Deprecation -> `qiskit.test.base` module is deprecated. | IK | BaseTestCase | `from qiskit_ibm_runtime.fake_provider import FakeVigo` |
| 7 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated. | IK | ReferenceCircuits.bell() | `qc = BellState().decompose()` |
| 9 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `execute()` function is deprecated. It has been moved to a method of the `QuantumCircuit` class | IK | execute | `job = qc.run(backend, shots=1024)` |
| 16 | `def test_bell_state(self):` | Deprecation -> `execute()` function is deprecated. It has been moved to a method of the `QuantumCircuit` class | IK | execute | `job = qc.run(backend, shots=1024)` |
| 17 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated. | IK | ReferenceCircuits.bell() | `qc = BellState().decompose()` |
| 19 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `execute()` function is deprecated. It has been moved to a method of the `QuantumCircuit` class | IK | execute | `job = qc.run(backend, shots=1024)` |