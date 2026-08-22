| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The `execute` function is deprecated. | internal | execute | `from qiskit import QuantumCircuit` |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Module relocation -> `Aer` is moved to the `qiskit_aer` package. | internal | Aer | `from qiskit_aer import Aer` |
| 12 | `job = execute(circuit, simulator, shots=1024)` | Deprecation -> The `execute` function is deprecated. | internal | execute | `job = simulator.run(circuit, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.visualization import plot_histogram

circuit = QuantumCircuit(2, 2)
circuit.h(0)
circuit.cx(0, 1)
circuit.measure([0, 1], [0, 1])

simulator = Aer.get_backend('qasm_simulator')
job = simulator.run(circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)

plot_histogram(counts)
```