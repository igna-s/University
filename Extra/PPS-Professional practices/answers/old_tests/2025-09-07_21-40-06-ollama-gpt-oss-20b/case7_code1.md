| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 1 | `from qiskit import execute` | * | Deprecation -> `qiskit.execute` is deprecated | `qiskit.execute` | |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | * | Deprecation -> `qiskit.test.reference_circuits` module deprecated | `qiskit.test.reference_circuits` | `from qiskit.circuit import QuantumCircuit` |
| 4 | `from qiskit.test.base import BaseTestCase` | * | Deprecation -> `qiskit.test.base.BaseTestCase` deprecated | `qiskit.test.base.BaseTestCase` | `from unittest import TestCase` |
| 7 | `qc = ReferenceCircuits.bell()` | * | Deprecation -> `ReferenceCircuits.bell()` deprecated | `ReferenceCircuits.bell()` | `qc = QuantumCircuit(2, 2)\nqc.h(0)\nqc.cx(0, 1)` |
| 9 | `job = execute(qc, backend, shots=1024)` | * | Deprecation -> `execute()` function deprecated | `execute()` | `job = backend.run(qc, shots=1024)` |
| 16 | `class TestBellCircuit(BaseTestCase):` | * | Deprecation -> `BaseTestCase` deprecated | `BaseTestCase` | `class TestBellCircuit(unittest.TestCase):` |
| 19 | `qc = ReferenceCircuits.bell()` | * | Deprecation -> `ReferenceCircuits.bell()` deprecated | `ReferenceCircuits.bell()` | `qc = QuantumCircuit(2, 2)\nqc.h(0)\nqc.cx(0, 1)` |
| 21 | `job = execute(qc, backend, shots=1024)` | * | Deprecation -> `execute()` function deprecated | `execute()` | `job = backend.run(qc, shots=1024)` |