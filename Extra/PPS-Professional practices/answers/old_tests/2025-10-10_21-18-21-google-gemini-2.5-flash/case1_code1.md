| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> `execute` function and `Aer` access are deprecated | internal | `execute`, `Aer` | `from qiskit import QuantumCircuit` |
| 9 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend()` is deprecated | internal | `Aer.get_backend` | `simulator = AerSimulator()` |
| 10 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> `execute()` function is deprecated | internal | `execute` | `job = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
fig = plot_histogram(counts)
```