| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :------- | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, Aer, execute` | Deprecation -> `qiskit.Aer` and `qiskit.execute` are deprecated. | internal | `Aer`, `execute` | `from qiskit_aer import AerSimulator` and remove `execute` |
| 10 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | internal | `Aer.get_backend` | `simulator = AerSimulator()` |
| 11 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> `qiskit.execute` is deprecated. | internal | `execute` | `job = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

# Create a quantum circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

# Simulate using Aer
simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
print(counts)
```