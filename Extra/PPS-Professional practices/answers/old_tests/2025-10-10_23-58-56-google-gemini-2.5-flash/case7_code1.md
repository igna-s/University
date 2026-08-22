| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> `qiskit.execute` function is deprecated | internal | qiskit.execute | |
| 2 | `from qiskit.test.mock import FakeVigo` | Deprecation -> `qiskit.test.mock` module is deprecated | internal | qiskit.test.mock.FakeVigo | `from qiskit.providers.fake_provider import FakeVigo` |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | Deprecation -> `qiskit.test.reference_circuits` module is deprecated | internal | qiskit.test.reference_circuits.ReferenceCircuits | `from qiskit.circuit.library import BellState` |
| 4 | `from qiskit.test.base import BaseTestCase` | Deprecation -> `qiskit.test.base` module is deprecated | internal | qiskit.test.base.BaseTestCase | `from unittest import TestCase` |
| 6 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated | internal | ReferenceCircuits.bell | `from qiskit.circuit.library import BellState` then `qc = BellState()` |
| 8 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `qiskit.execute` function is deprecated | internal | qiskit.execute | `job = backend.run(qc, shots=1024)` |
| 15 | `qc = ReferenceCircuits.bell()` | Deprecation -> `ReferenceCircuits.bell()` is deprecated | internal | ReferenceCircuits.bell | `from qiskit.circuit.library import BellState` then `qc = BellState()` |
| 17 | `job = execute(qc, backend, shots=1024)` | Deprecation -> `qiskit.execute` function is deprecated | internal | qiskit.execute | `job = backend.run(qc, shots=1024)` |