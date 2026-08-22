| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.visualization import plot_histogram` | Deprecation -> The `qiskit.visualization` module has been removed. Its contents have been moved to other packages. (optional) | internal | qiskit.visualization | `from qiskit.visualization.histogram import plot_histogram` |
| 4 | `qc = QuantumCircuit(2, 2)` | Deprecation -> `QuantumCircuit` no longer supports an implicit classical bit declaration from the second argument of its constructor, if you want to declare classical bits you must declare `ClassicalRegister` and pass it to the constructor. | internal | QuantumCircuit | `cr = ClassicalRegister(2)`<br>`qc = QuantumCircuit(2, cr)` |
| 11 | `simulator = AerSimulator()` | Deprecation -> `AerSimulator` is deprecated in `qiskit-aer`. To migrate, install `qiskit-aer` and import `AerSimulator` from `qiskit_aer`. | internal | AerSimulator | `from qiskit_aer import AerSimulator` |
| 13 | `transpiled_circuit = transpile(qc, simulator)` | Deprecation -> `qiskit.compiler.transpile` is deprecated. Use `qiskit.transpiler.transpile` instead. | internal | transpile | `from qiskit.transpiler import transpile` |
| 15 | `job = simulator.run(transpiled_circuit, shots=1024)` | Refactor -> The `run()` method of `AerSimulator` does not accept a list of circuits. You must pass a single circuit or a list of circuits, but not a list with a single circuit. | internal | run | `job = simulator.run(transpiled_circuit, shots=1024)` |
| 18 | `qc.draw('mpl')` | Deprecation -> The `QuantumCircuit.draw()` method has changed its default output to `'text'`. To retain the previous behavior, specify `output='mpl'`. (optional) | internal | QuantumCircuit.draw | `qc.draw(output='mpl')` |


```python
from qiskit import QuantumCircuit, ClassicalRegister
from qiskit_aer import AerSimulator
from qiskit.transpiler import transpile
from qiskit.visualization.histogram import plot_histogram

cr = ClassicalRegister(2)
qc = QuantumCircuit(2, cr)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

simulator = AerSimulator()
transpiled_circuit = transpile(qc, simulator)
job = simulator.run(transpiled_circuit, shots=1024)
result = job.result()
counts = result.get_counts(transpiled_circuit)
fig = plot_histogram(counts)
qc.draw(output='mpl')
```