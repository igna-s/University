| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The `execute` function is deprecated. Deprecation -> The `Aer` module from `qiskit` is deprecated; use `qiskit_aer` directly. | internal | qiskit.execute, qiskit.Aer | `from qiskit_aer import AerSimulator` |
| 7 | `backend = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` is deprecated. | internal | Aer.get_backend | `backend = AerSimulator()` |
| 8 | `job = execute(qc, backend, shots=1024)` | Deprecation -> The `execute` function is deprecated; use `backend.run()` instead. | internal | execute | `job = backend.run(qc, shots=1024)` |


```python
from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
from qiskit.visualization import plot_histogram

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

backend = AerSimulator()
job = backend.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)

print("Counts:", counts)
plot_histogram(counts)
```