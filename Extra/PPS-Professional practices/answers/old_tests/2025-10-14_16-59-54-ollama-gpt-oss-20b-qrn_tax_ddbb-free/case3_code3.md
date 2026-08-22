| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------:| :------- | :---------- |
| 9 | `parsed_circuit = qasm.loads(qasm_str)` | Updated -> qasm.loads() now returns tuple (circuit, metadata) | IK | qasm.loads | `parsed_circuit, _ = qasm.loads(qasm_str)` |

```python
from qiskit import QuantumCircuit               # type: ignore
from qiskit import qasm2 as qasm                # type: ignore
from qiskit_aer import AerSimulator             # type: ignore

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qasm.dumps(qc)
parsed_circuit, _ = qasm.loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```