| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 3 | `from qiskit.test.reference_circuits import ReferenceCircuits` | `*` | Deprecation -> `qiskit.test.reference_circuits` module import discouraged for general circuit creation (optional) | `qiskit.test.reference_circuits` | `from qiskit import QuantumCircuit` |
| 5 | `qc = ReferenceCircuits.bell()` | `*` | Deprecation -> `ReferenceCircuits.bell()` replaced by explicit `QuantumCircuit` construction (optional) | `ReferenceCircuits.bell()` | 
```python\nqc = QuantumCircuit(2, 2)\nqc.h(0)\nqc.cx(0, 1)\nqc.measure([0, 1], [0, 1])\n```
 |