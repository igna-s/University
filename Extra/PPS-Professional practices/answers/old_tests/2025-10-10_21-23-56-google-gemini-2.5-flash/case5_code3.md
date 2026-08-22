| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The `execute` function is deprecated | internal | `qiskit.execute` | remove `execute` from import |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> `Aer` module access is changing | internal | `qiskit.Aer` | `from qiskit_aer import AerSimulator` |
| 10 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated | internal | `Aer.get_backend` | `simulator = AerSimulator()` |
| 11 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> The `execute` function is deprecated | internal | `execute` | `job = simulator.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.visualization import plot_histogram

# Build a quantum circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

# Simulate the circuit
simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)

# Plot results
plot_histogram(counts)
```