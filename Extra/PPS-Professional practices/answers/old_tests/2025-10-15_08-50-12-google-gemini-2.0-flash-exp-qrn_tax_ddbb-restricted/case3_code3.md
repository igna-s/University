| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Module Renamed -> The qasm2 module has been renamed to qasm | qrn_tax_ddbb-f4f99f0d-9f1f-441d-a58a-d3a96896a811 | qasm2 | `from qiskit import qasm` |

```python
from qiskit import QuantumCircuit
from qiskit import qasm
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