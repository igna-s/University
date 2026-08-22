| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The global `execute` function is deprecated. | internal | `execute` | |
| 1 | `from qiskit import QuantumCircuit, execute, Aer` | Deprecation -> The `Aer` object (used with `get_backend`) is deprecated. | internal | `Aer` | |
| 10 | `simulator = Aer.get_backend('qasm_simulator')` | Deprecation -> `Aer.get_backend` method is deprecated. | internal | `Aer.get_backend` | `AerSimulator()` |
| 11 | `job = execute(qc, simulator, shots=1024)` | Deprecation -> The global `execute` function is deprecated. | internal | `execute` | `simulator.run(qc, shots=1024)` |
| 17 | `job_statevector = execute(qc, simulator_statevector, shots=1)` | Deprecation -> The global `execute` function is deprecated. | internal | `execute` | `simulator_statevector.run(qc, shots=1)` |


```python
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram, plot_bloch_multivector
from qiskit.providers.aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

simulator = AerSimulator()
job = simulator.run(qc, shots=1024)
result = job.result()
counts = result.get_counts(qc)
print(counts)

simulator_statevector = AerSimulator(method='statevector')
job_statevector = simulator_statevector.run(qc, shots=1)
result_statevector = job_statevector.result()
statevector = result_statevector.get_statevector(qc)
print(statevector)
```