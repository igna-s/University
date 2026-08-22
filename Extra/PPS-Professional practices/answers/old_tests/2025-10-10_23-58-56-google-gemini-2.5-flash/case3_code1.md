| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit.qasm import Qasm` | Deprecation -> The `qiskit.qasm` module has been deprecated | internal | qiskit.qasm | `from qiskit.qasm3 import QASM3Parser` |
| 4 | `circuit2 = Qasm(filename=qasm_file)` | Deprecation -> The `Qasm` class has been deprecated | internal | Qasm | `parser = QASM3Parser(qasm_file)` |
| 5 | `program2 = circuit2.parse()` | Deprecation -> The `parse()` method of the `Qasm` class has been deprecated | internal | parse() | `program2 = parser.parse()` |
| 6 | `qc2 = program2.get_circuit()` | Deprecation -> The `get_circuit()` method of the `Qasm` class has been deprecated | internal | get_circuit() | `qc2 = program2.to_circuit()` |