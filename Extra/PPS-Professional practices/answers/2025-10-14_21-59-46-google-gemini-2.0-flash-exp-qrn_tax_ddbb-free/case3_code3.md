| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit import qasm2 as qasm` | Removal -> The qasm2 module has been removed from qiskit | qrn_tax_ddbb-69a5707f | qiskit.qasm2 |  |
| 5 | `qc.measure_all()` | Deprecation -> The QuantumCircuit.measure_all() method is deprecated and will be removed in a future release. | qrn_tax_ddbb-e4479654 | QuantumCircuit.measure_all | `qc.measure([0,1], [0,1])` |

```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0,1], [0,1])

simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts()
print(counts)
```