| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :-------: | :---------- |
| 2 | `from mylib import execute, getBackend` | Deprecation -> The global `qiskit.execute` function is deprecated. (optional) | * | internal | `execute` (from mylib) | |
| 2 | `from mylib import execute, getBackend` | Deprecation -> Backend instantiation via `get_backend` is deprecated. (optional) | * | internal | `getBackend` (from mylib) | |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` module moved | * | internal | `qiskit.tools.visualization` | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> `qiskit.tools.monitor` module moved | * | internal | `qiskit.tools.monitor` | `from qiskit.utils.job_monitor import job_monitor` |
| 15 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> Obtaining backends via `get_backend` is deprecated, use direct instantiation of `AerSimulator`. | * | internal | `getBackend.get_backend` | `simulator = AerSimulator(method='statevector')` |
| 16 | `result = execute(qc, simulator).result()` | Deprecation -> `qiskit.execute` function is deprecated, use `backend.run()`. | * | internal | `execute` | `result = simulator.run(qc).result()` |
| 19 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> Obtaining backends via `get_backend` is deprecated, use direct instantiation of `AerSimulator`. | * | internal | `getBackend.get_backend` | `backend = AerSimulator()` |
| 20 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `qiskit.execute` function is deprecated, use `backend.run()`. | * | internal | `execute` | `job = backend.run(qc, shots=1000)` |


```python
from qiskit import QuantumCircuit
from qiskit.visualization import plot_histogram
from qiskit.utils.job_monitor import job_monitor
from qiskit_aer import AerSimulator
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = AerSimulator(method='statevector')
result = simulator.run(qc).result()
statevector = result.get_statevector()

backend = AerSimulator()
job = backend.run(qc, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```