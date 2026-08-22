| Line | Scenario                                                                 | Reference                                   | Artifact                      | Refactoring                                                                                                         |
|------|---------------------------------------------------------------------------|---------------------------------------------|------------------------------|----------------------------------------------------------------------------------------------------------------------|
| 1    | Importing `Aer` from `qiskit` is deprecated.                              | qrn_notax_ddbb--2125b2ad-3e2e-494b-b0de-816d0703f19c | Aer                           | `from qiskit import QuantumCircuit, execute`<br>`from qiskit_aer import Aer`                                       |
| 2    | Importing `qasm2` as a module; older API will be removed.                 | qrn_notax_ddbb--508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qasm2                         | `from qiskit.qasm2 import dumps, loads`                                                                              |
| 9    | Using deprecated `qc.qasm()` to obtain QASM.                              | qrn_notax_ddbb--508fb6f3-cdfc-4b96-ad81-f550801dbe2f | QuantumCircuit.qasm()          | `qasm_str = dumps(qc)`                                                                                                 |
| 11   | Creating and parsing a `qasm.Qasm` object is obsolete.                    | qrn_notax_ddbb--508fb6f3-cdfc-4b96-ad81-f550801dbe2f | qasm.Qasm / program.parse()    | `circuit = loads(qasm_str)`                                                                                        |
| 16   | Executing the parsed QASM string; should execute the circuit.             | IK                                           | execute                       | `job = execute(circuit, simulator, shots=1024)`                                                                    |
| 18   | Retrieving counts from a QASM string; should use the circuit.             | IK                                           | Result.get_counts             | `counts = result.get_counts(circuit)`                                                                               |

```python
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
from qiskit.qasm2 import dumps, loads

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = dumps(qc)

circuit = loads(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```