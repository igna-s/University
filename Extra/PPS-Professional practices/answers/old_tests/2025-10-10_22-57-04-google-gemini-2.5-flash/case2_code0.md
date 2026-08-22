| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import execute` | Deprecation -> The `execute` function is deprecated | internal | `qiskit.execute` | `from qiskit.transpiler import transpile` |
| 2 | `from qiskit.providers.aer import AerSimulator` | Deprecation -> The `qiskit.providers.aer` module is deprecated | internal | `qiskit.providers.aer.AerSimulator` | `from qiskit.primitives import Sampler` |
| 3 | `from qiskit import QuantumCircuit, transpile` | Deprecation -> `qiskit.transpile` is deprecated and `qiskit.compiler` is removed | internal | `qiskit.transpile` | `from qiskit import QuantumCircuit` |
| 5 | `qc = QuantumCircuit(2, 2)` | Refactor -> `QuantumCircuit` no longer supports `qiskit.execute` | internal | `QuantumCircuit` | `qc = QuantumCircuit(2, 2)` |
| 7 | `qc.h(0)` | Refactor -> `QuantumCircuit.h` | internal | `QuantumCircuit.h` | `qc.h(0)` |
| 8 | `qc.cx(0, 1)` | Refactor -> `QuantumCircuit.cx` | internal | `QuantumCircuit.cx` | `qc.cx(0, 1)` |
| 9 | `qc.measure([0, 1], [0, 1])` | Refactor -> `QuantumCircuit.measure` | internal | `QuantumCircuit.measure` | `qc.measure([0, 1], [0, 1])` |
| 11 | `simulator = AerSimulator()` | Deprecation -> `AerSimulator` is deprecated | internal | `AerSimulator` | `simulator = Sampler()` |
| 12 | `compiled_circuit = transpile(qc, simulator)` | Refactor -> `transpile` no longer accepts a simulator as a backend. `transpile` is for backends only | internal | `transpile` | `sampler = Sampler()` |
| 14 | `job = execute(compiled_circuit, simulator, shots=1024)` | Deprecation -> `execute` function is deprecated | internal | `execute` | `job = sampler.run(qc, shots=1024)` |
| 15 | `result = job.result()` | Refactor -> `result` method is refactored | internal | `result` | `result = job.result()` |
| 16 | `counts = result.get_counts(compiled_circuit)` | Refactor -> `get_counts` is deprecated for Sampler | internal | `get_counts` | `quasi_distributions = result.quasi_distributions[0]` |
| 18 | `from qiskit.visualization import plot_histogram` | Deprecation -> `qiskit.visualization.plot_histogram` is deprecated | internal | `qiskit.visualization.plot_histogram` | `from qiskit.visualization import plot_histogram` |
| 19 | `fig = plot_histogram(counts)` | Refactor -> `plot_histogram` can be used with Sampler results by converting quasi_distributions to counts | internal | `plot_histogram` | `counts = {format(i, '02b'): v for i, v in quasi_distributions.binary_probabilities().items()}` |
| 20 | `fig.show()` | Refactor -> `fig.show()` is not directly compatible with the new Sampler output. | internal | `fig.show` | `fig = plot_histogram(counts)` |


```python
from qiskit.transpiler import transpile
from qiskit.primitives import Sampler
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

sampler = Sampler()

job = sampler.run(qc, shots=1024)
result = job.result()
quasi_distributions = result.quasi_distributions[0]
counts = {format(i, '02b'): v for i, v in quasi_distributions.binary_probabilities().items()}

fig = plot_histogram(counts)
```