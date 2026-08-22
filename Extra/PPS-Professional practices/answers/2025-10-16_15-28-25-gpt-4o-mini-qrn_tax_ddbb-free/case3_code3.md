| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 2 | `from qiskit import qasm` | Deprecation -> qiskit.qasm module is deprecated | qrn_tax_ddbb--f24d40d4-9a98-4431-85f5-3e6f98fee373 | qiskit.qasm | `from qiskit import qasm2` |
| 7 | `qasm_str = qasm.dumps(qc)` | Updated -> qasm.dumps() function | qrn_tax_ddbb--084696d9-2c75-437a-8e84-96506e6766aa | qasm2 | `qasm_str = qasm.dumps(qc)` |
| 8 | `parsed_circuit = qasm.loads(qasm_str)` | Updated -> qasm.loads() function | qrn_tax_ddbb--084696d9-2c75-437a-8e84-96506e6766aa | qasm2 | `parsed_circuit = qasm.loads(qasm_str)` |
| 3 | `from qiskit_aer import AerSimulator` | Deprecation -> qiskit.providers.aer is deprecated | qrn_tax_ddbb--00000000-0000-0000-0000-000000000000 | qiskit.providers.aer | `from qiskit_aer import AerSimulator` |

```python
from qiskit import QuantumCircuit
from qiskit import qasm2 as qasm
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

qasm_str = qasm.dumps(qc)
parsed_circuit = qasm.loads(qasm_str)

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```