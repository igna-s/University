| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Removal -> The ``qasm2`` module has been removed from Qiskit. | qrn_ddbb-216a178d3cc448a1a724ef95a81022c5 | qasm2 |  |
| 9 | `qasm_str = qasm.dumps(qc)` | Removal -> The ``qasm2`` module has been removed from Qiskit. | qrn_ddbb-597e64c2138247c9a746f916f434c083 | qasm2 |  |
| 10 | `parsed_circuit = qasm.loads(qasm_str)` | Removal -> The ``qasm2`` module has been removed from Qiskit. | qrn_ddbb-c92d1755e38345e9a939384339f71ae7 | qasm2 |  |

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```