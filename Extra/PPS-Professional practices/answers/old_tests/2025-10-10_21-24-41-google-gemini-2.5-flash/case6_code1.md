| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute` | Deprecation -> The `execute` function is deprecated | internal | execute | `from qiskit import QuantumCircuit` |
| 2 | `from qiskit.providers.aer import AerSimulator` | Deprecation -> The `AerSimulator` class has moved to `qiskit_aer` | internal | qiskit.providers.aer.AerSimulator | `from qiskit_aer import AerSimulator` |
| 12 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> The `execute` function is deprecated; use `backend.run(circuit, **kwargs)` instead | internal | execute | `job = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

# Create a quantum circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

# Use AerSimulator
simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
print(counts)
```