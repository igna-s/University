| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 12 | `simulator = Aer.get_backend('aer_simulator')` | Deprecation -> `Aer.get_backend()` function is deprecated. | internal | `Aer.get_backend` | `simulator = AerSimulator()` |
| 15 | `job = execute(circ, simulator, shots=1000)` | Deprecation -> `execute()` function is deprecated. | internal | `execute` | `job = simulator.run(circ, shots=1000)` |


```python
import numpy as np
from qiskit import QuantumCircuit, transpile
from qiskit_aer import AerSimulator
from qiskit.visualization import plot_histogram

# Construct quantum circuit
circ = QuantumCircuit(3, 3)
circ.h(0)
circ.cx(0, 1)
circ.cx(0, 2)
circ.measure([0, 1, 2], [0, 1, 2])

# Select the AerSimulator
simulator = AerSimulator()

# Execute and get counts
job = simulator.run(circ, shots=1000)
result = job.result()
counts = result.get_counts(circ)
print("Total counts are:", counts)

# Draw the circuit
circ.draw('mpl')

# Plot a histogram
plot_histogram(counts)
```