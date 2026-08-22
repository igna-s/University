| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> `Aer` module is deprecated. (optional) | internal | Aer | `from qiskit_aer import AerSimulator` |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> `execute` function is deprecated. | internal | execute | |
| 2 | `from qiskit.utils import QuantumInstance` | Deprecation -> `QuantumInstance` class is deprecated. | internal | QuantumInstance | |
| 9 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | internal | Aer.get_backend | `backend = AerSimulator()` |
| 10 | `job = execute(qc, backend, shots=1024)` | Deprecation -> The global `execute` function is deprecated. | internal | execute | `job = backend.run(qc, shots=1024)` |
| 15 | `qi = QuantumInstance(simulator, shots=1024)` | Deprecation -> `QuantumInstance` class is deprecated. | internal | QuantumInstance | |
| 16 | `job_qi = qi.execute(qc)` | Deprecation -> `QuantumInstance.execute` is deprecated. | internal | QuantumInstance.execute | `job_qi = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator

# Create a quantum circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

# Using AerSimulator directly and backend.run()
backend = AerSimulator()
job = backend.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
print(f"Counts (AerSimulator + run): {counts}")

# Simplified approach without QuantumInstance
simulator = AerSimulator()
job_qi = simulator.run(qc, shots=1024)
result_qi = job_qi.result()
counts_qi = result_qi.get_counts(qc)
print(f"Counts (AerSimulator direct run): {counts_qi}")
```