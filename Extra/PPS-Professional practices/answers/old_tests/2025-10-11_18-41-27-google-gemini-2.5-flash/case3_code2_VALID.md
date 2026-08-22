| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> qasm2 module is deprecated | * | internal | qasm2 | `from qiskit.qasm2 import Qasm2` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> Qasm class removed | * | internal | Qasm | `qasm_parser = Qasm2()` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> Qasm class removed | * | internal | Qasm | `program = qasm_parser.parse(qasm_str)` |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Incorrect use of parser object for execution | * | internal | execute | `job = execute(circuit, simulator, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Incorrect use of parser object for counts | * | internal | get_counts | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, Aer, execute
from qiskit.qasm2 import Qasm2

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qc.qasm()

qasm_parser = Qasm2()
program = qasm_parser.parse(qasm_str)
circuit = program.get_circuit()

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```
