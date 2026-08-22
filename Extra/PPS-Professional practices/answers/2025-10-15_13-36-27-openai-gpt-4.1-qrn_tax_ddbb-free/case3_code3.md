| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import qasm2 as qasm | Deprecation -> qasm2 module removed; use qiskit.qasm2 directly | qrn_tax_ddbb--ad94f009-b5b0-4e47-bb23-e0dbfb26a569 | qasm2 | from qiskit.qasm2 import dumps, loads |

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