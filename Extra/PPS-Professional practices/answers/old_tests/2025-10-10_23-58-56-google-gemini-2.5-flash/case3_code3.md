| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm                # type: ignore` | Deprecation -> The `qiskit.qasm2` module is deprecated and removed. | internal | qiskit.qasm2 | |
| 10 | `qasm_str = qasm.dumps(qc)` | Deprecation -> The `qiskit.qasm2.dumps()` function is deprecated. | internal | qasm.dumps | `qasm_str = qc.qasm()` |
| 11 | `parsed_circuit = qasm.loads(qasm_str)` | Deprecation -> The `qiskit.qasm2.loads()` function is deprecated. | internal | qasm.loads | `parsed_circuit = QuantumCircuit.from_qasm_str(qasm_str)` |