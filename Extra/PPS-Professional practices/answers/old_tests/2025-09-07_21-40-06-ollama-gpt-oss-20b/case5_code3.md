| Line | Code | Scenario Id | Scenario | Artifact | Refactoring |
| :-: | :- | :-: | :- | :- | :- |
| 2 | `from qiskit.extensions import UnitaryGate` | * | Module Migration -> UnitaryGate moved to qiskit.circuit.library | qiskit.extensions.UnitaryGate | `from qiskit.circuit.library import UnitaryGate` |
| 3 | `from qiskit.extensions.exceptions import ExtensionError` | * | Module Migration -> ExtensionError moved to qiskit.circuit.exceptions, consider using CircuitError | qiskit.extensions.exceptions.ExtensionError | `from qiskit.circuit.exceptions import CircuitError` |