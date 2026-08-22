| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, transpile` | Deprecation -> The `transpile` function is deprecated. It has been moved to `qiskit.transpiler.transpile`. | internal | transpile | `from qiskit.transpiler import transpile` |
| 2 | `from qiskit.visualization import plot_histogram` | Deprecation -> `qiskit.visualization.plot_histogram` is deprecated. It has been moved to `qiskit.visualization.plot.plot_histogram`. | internal | plot_histogram | `from qiskit.visualization.plot import plot_histogram` |
| 3 | `from qiskit_aer import AerSimulator` | Deprecation -> `qiskit_aer.AerSimulator` is deprecated. It has been moved to `qiskit_aer.AerSimulator` is deprecated. Use `qiskit_aer.primitives.AerSimulator` instead. | internal | AerSimulator | `from qiskit_aer.primitives import AerSimulator` |
| 5 | `circuit = QuantumCircuit(2, 2)` | (optional) -> For circuits with a small number of qubits, it is more efficient to directly use `QuantumCircuit` with its number of qubits and bits. For more complex circuits, `QuantumCircuit` can be initialized with `qiskit.QuantumRegister` and `qiskit.ClassicalRegister`. | internal | QuantumCircuit | `circuit = QuantumCircuit(2)` |
| 10 | `simulator = AerSimulator()` | Deprecation -> `AerSimulator()` is deprecated. It has been moved to `AerSimulator().run`. | internal | AerSimulator | `simulator = AerSimulator()` |
| 11 | `compiled_circuit = transpile(circuit, simulator)` | Deprecation -> `transpile` function will be deprecated in a future release. It has been moved to `qiskit.transpiler.transpile`. | internal | transpile | `compiled_circuit = transpile(circuit, backend=simulator)` |
| 13 | `job = simulator.run(compiled_circuit, shots=1024)` | Deprecation -> The `run` method in `AerSimulator` is deprecated. Use `job = simulator.run(compiled_circuit).result()` instead. | internal | AerSimulator.run | `job = simulator.run(compiled_circuit, shots=1024)` |
| 14 | `result = job.result()` | Deprecation -> The `result` method is deprecated. Use `job.result()` instead. | internal | job.result | `result = job.result()` |
| 15 | `counts = result.get_counts(circuit)` | Deprecation -> The `get_counts` method is deprecated. Use `result.get_counts(circuit)` instead. | internal | result.get_counts | `counts = result.get_counts(circuit)` |
| 17 | `plot_histogram(counts)` | Deprecation -> The `plot_histogram` function is deprecated. It has been moved to `qiskit.visualization.plot.plot_histogram`. | internal | plot_histogram | `plot_histogram(counts)` |


```python
from qiskit import QuantumCircuit
from qiskit.transpiler import transpile
from qiskit.visualization.plot import plot_histogram
from qiskit_aer.primitives import AerSimulator

circuit = QuantumCircuit(2)
circuit.h(0)
circuit.cx(0, 1)
circuit.measure([0,1], [0,1])

simulator = AerSimulator()
compiled_circuit = transpile(circuit, backend=simulator)
job = simulator.run(compiled_circuit, shots=1024)
result = job.result()
counts = result.get_counts(circuit)
plot_histogram(counts)
```