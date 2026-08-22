| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import qasm` | Deprecation -> The `qiskit.qasm` module has been removed | internal | qiskit.qasm | `from qiskit.qasm2 import loads` |
| 7 | `qasm_str = """` | (optional) -> In Qiskit 1.0, the `qiskit.qasm` module was removed and replaced by `qiskit.qasm2` which provides `loads` and `dumps` to convert between QASM 2.0 strings and `QuantumCircuit` objects. | internal | qasm_str | `from qiskit.qasm2 import loads` |
| 13 | `circuit1 = qasm.Qasm(data=qasm_str)` | Deprecation -> `qiskit.qasm.Qasm` is removed | internal | qiskit.qasm.Qasm | `circuit1 = loads(qasm_str)` |
| 14 | `program1 = circuit1.parse()` | Deprecation -> `qiskit.qasm.Qasm.parse()` is removed | internal | qiskit.qasm.Qasm.parse | |
| 15 | `qc1 = program1.get_circuit()` | Deprecation -> `get_circuit()` is removed | internal | get_circuit | |