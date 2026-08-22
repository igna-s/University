| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Deprecation of qiskit.Aer object | 0771d384-706f-40c0-818d-20a4b728e9a2 | qiskit.Aer | `from qiskit_aer import Aer` |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> The `execute` function has been removed | IK | execute | |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> `qiskit.qasm2` module is deprecated | IK | qiskit.qasm2 | `from qiskit.qasm import loads` |
| 10 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> `qiskit.qasm2.Qasm` is deprecated | IK | qasm.Qasm | `qasm_qc = loads(qasm_str)` |
| 11 | `program = qasm_qc.parse()` | Deprecation -> `qiskit.qasm2.Qasm.parse()` is deprecated | IK | qasm_qc.parse | |
| 12 | `circuit = program.get_circuit()` | Deprecation -> `qiskit.qasm2.Program.get_circuit()` is deprecated | IK | program.get_circuit | `circuit = qasm_qc` |
| 14 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> The `execute` function has been removed | IK | execute | `job = simulator.run(qasm_qc, shots=1024)` |
| 16 | `counts = result.get_counts(qasm_qc)` | Deprecation -> `result.get_counts()` no longer accepts a circuit object | IK | result.get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.qasm import loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_qc = loads(qasm_str)
circuit = qasm_qc

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```