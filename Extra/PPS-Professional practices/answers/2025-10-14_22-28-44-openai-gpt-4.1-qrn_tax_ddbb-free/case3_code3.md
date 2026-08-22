| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | from qiskit import qasm2 as qasm | Removal -> `qiskit.qasm2` module removed in Qiskit 1.0 | qrn_tax_ddbb-90d033ae173649ff8c8d45ce91e08ea9 | qiskit.qasm2 |  |
| 7 | qasm_str = qasm.dumps(qc) | Removal -> `qasm2.dumps()` not available (must use assembly or exporter APIs) | qrn_tax_ddbb-0b80674a72ef40e8befb8e4f7b21f6ae | qasm2.dumps |  |
| 8 | parsed_circuit = qasm.loads(qasm_str) | Removal -> `qasm2.loads()` not available (must use assembly or exporter APIs) | qrn_tax_ddbb-0b80674a72ef40e8befb8e4f7b21f6ae | qasm2.loads |  |

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

parsed_circuit = qc

simulator = AerSimulator()
job = simulator.run(parsed_circuit, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```