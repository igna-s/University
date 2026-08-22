| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 6 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> The `Aer.get_backend()` method is deprecated. | internal | Aer.get_backend | `simulator = AerSimulator()` |
| 7 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> The `qiskit.execute()` function is deprecated. | internal | qiskit.execute | `job = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
print(counts)
```