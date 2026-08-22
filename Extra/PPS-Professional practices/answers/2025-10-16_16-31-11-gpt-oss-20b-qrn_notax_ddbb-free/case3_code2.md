| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> Aer import from qiskit is deprecated | IK | Aer | `from qiskit import QuantumCircuit, execute`<br>`from qiskit_aer import Aer` |
| 2 | `from qiskit import qasm2 as qasm` | Deprecation -> qasm2 import from qiskit root is deprecated | IK | qasm2 | `import qiskit.qasm2 as qasm` |
| 9 | `qasm_str = qc.qasm()` | Deprecation -> QuantumCircuit.qasm() is deprecated | IK | QuantumCircuit.qasm | `qasm_str = qasm.dumps(qc)` |
| 11 | `qasm_qc = qasm.Qasm(data=qasm_str)` | Deprecation -> qasm2.Qasm class is deprecated | IK | qasm2.Qasm | `circuit = qasm.loads(qasm_str)` |
| 12 | `program = qasm_qc.parse()` | Deprecation -> qasm2.Qasm.parse() is deprecated | IK | qasm2.Qasm.parse | removed |
| 13 | ` شبكة = program.get_circuit()` | Deprecation -> qasm2.Qasm.get_circuit() is deprecated | IK | qasm2.Qasm.get_circuit | removed |
| 16 | `job = execute(qasm_qc, simulator, shots=1024)` | Deprecation -> execute expects QuantumCircuit, not Qasm | IK | execute argument | `job = execute(circuit, simulator, shots=1024)` |
| 18 | `counts = result.get_counts(qasm_qc)` | Deprecation -> result.get_counts expects QuantumCircuit | IK | result.get_counts argument | `counts = result.get_counts(circuit)` |

```python
from qiskit import QuantumCircuit, execute
from qiskit_aer import Aer
import qiskit.qasm2 as qasm

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

qasm_str = qasm.dumps(qc)
circuit = qasm.loads(qasm_str)

simulator = Aer.get_backend('qasm_simulator')
job = execute(circuit, simulator, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
print(counts)
```