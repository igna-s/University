| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` |  Deprecated -> The `execute` function is deprecated and will be removed in a future release. | qrn_tax_ddbb-48a786141e3547d6b094e492a31408e2 | `execute` | Use `backend.run` instead.  |
| 2 | `from qiskit import qasm2 as qasm` |  Package rename -> The package qasm2 has been renamed to qasm3. | qrn_tax_ddbb-e54efc019d2d423ca1ca37b687374b55 | `qasm2` | `from qiskit import qasm3 as qasm` |
| 12 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecated -> The `execute` function is deprecated and will be removed in a future release. | qrn_tax_ddbb-48a786141e3547d6b094e492a31408e2 | `execute` | `job = simulator.run(qasm_qc, shots=1024)` |
| 14 | `counts = result.get_counts(qasm_qc)` | Deprecated -> Passing a circuit to `get_counts` is deprecated and will be removed in a future release. | qrn_tax_ddbb-a9295e1917974405a040a429904b7634 | `get_counts` | `counts = result.get_counts()` |

```python
from qiskit import QuantumCircuit, Aer
from qiskit import qasm3 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(qasm_qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```