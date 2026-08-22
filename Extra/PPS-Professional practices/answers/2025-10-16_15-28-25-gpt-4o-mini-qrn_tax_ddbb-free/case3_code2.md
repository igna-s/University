| Line | Code                                                        | Scenario                                                    | Reference                                     | Artifact                             | Refactoring                                          |
| :--: | :-------------------------------------------------------- | :-------                                                  | :-----------------------------------------: | :------------------------------------ | :--------------------------------------------------- |
| 1    | `from qiskit import qasm2 as qasm`                       | Deprecation -> `qiskit.qasm` module is deprecated         | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm                        | `from qiskit import qasm2`                           |
| 16   | `qasm_str = qc.qasm()`                                    | Deprecation -> `QuantumCircuit.qasm()` method is deprecated| qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | QuantumCircuit.qasm                  | `qasm_str = qasm.dumps(qc)`                          |
| 21   | `job = execute(qasm_qc, simulator, shots=1024)`          | -                                                          | IK                                         | execute                              | -                                                    |
| 22   | `result = job.result()`                                   | -                                                          | IK                                         | result                               | -                                                    |
| 23   | `counts = result.get_counts(qasm_qc)`                    | -                                                          | IK                                         | get_counts                           | -                                                    |

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit import qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm.dumps(qc)

qasm_qc = qasm.Qasm(data=qasm_str)
program = qasm_qc.parse()
circuit = program.get_circuit()

simulator = Aer.get_backend('qasm_simulator')
job = execute(qasm_qc, simulator, shots=1024)
result = job.result()
counts = result.get_counts(qasm_qc)
print(counts)
```