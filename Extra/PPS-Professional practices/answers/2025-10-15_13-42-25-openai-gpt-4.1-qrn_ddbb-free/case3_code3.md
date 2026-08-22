| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import qasm2 as qasm | Import Path Update -> qiskit.qasm2 uses new import location and functions | IK | qiskit.qasm2 | from qiskit.qasm2 import dumps, loads |
| 6 | qasm_str = qasm.dumps(qc) | API Change -> Use imported qasm2.dumps/loads, not import-as-object | IK | qiskit.qasm2.dumps | qasm_str = dumps(qc) |
| 7 | parsed_circuit = qasm.loads(qasm_str) | API Change -> Use imported qasm2.dumps/loads, not import-as-object | IK | qiskit.qasm2.loads | parsed_circuit = loads(qasm_str) |

```python
from qiskit import QuantumCircuit
from qiskit.qasm2 import dumps, loads
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = dumps(qc)
parsed_circuit = loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```