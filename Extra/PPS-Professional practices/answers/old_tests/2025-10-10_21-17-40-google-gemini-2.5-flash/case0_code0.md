| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 8 | `qc.measure_all()` | API Change -> The `measure_all()` method now returns a new circuit by default. To modify the circuit in place, the `inplace=True` argument must be used. | internal | QuantumCircuit.measure_all | `qc.measure_all(inplace=True)` |


```python
from qiskit import QuantumCircuit, transpile
from qiskit.providers.aer import AerSimulator
from qiskit.visualization import plot_histogram

# Create a quantum circuit
qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all(inplace=True)

# Simulate the circuit
simulator = AerSimulator()
compiled_circuit = transpile(qc, simulator)
job = simulator.run(compiled_circuit, shots=1024)
result = job.result()
counts = result.get_counts(compiled_circuit)

# Plot results
# plot_histogram(counts)
```