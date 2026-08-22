| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.visualization` module updated (optional) | Internal Knowledge | `qiskit.tools.visualization.plot_histogram` | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The `job_monitor` function has moved from `qiskit.tools.monitor` to `qiskit.providers.job` | Internal Knowledge | `qiskit.tools.monitor.job_monitor` | `from qiskit.providers.job import job_monitor` |
| 16 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> `get_backend` is deprecated from `qiskit.utils.run_circuits` to `qiskit.primitives` | Internal Knowledge | `getBackend.get_backend` | `from qiskit.primitives import Sampler` |
| 17 | `result = execute(qc, simulator).result()` | Deprecation -> `qiskit.execute` is deprecated. Replaced by `qiskit.primitives` | Internal Knowledge | `qiskit.execute` | `sampler = Sampler()` <br> `job = sampler.run(qc)` <br> `result = job.result()` |
| 17 | `result = execute(qc, simulator).result()` | Deprecation -> `qiskit.execute` is deprecated. Replaced by `qiskit.primitives` | Internal Knowledge | `qiskit.execute` | `job = sampler.run(qc)` |
| 18 | `statevector = result.get_statevector()` | Deprecation -> The `get_statevector` method is deprecated. | Internal Knowledge | `result.get_statevector` | `statevector = result.quasi_dists[0].binary_probabilities()` |
| 20 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> `get_backend` is deprecated from `qiskit.utils.run_circuits` to `qiskit.primitives` | Internal Knowledge | `getBackend.get_backend` | `from qiskit_aer import AerSimulator` <br> `backend = AerSimulator()` |
| 21 | `job = execute(qc, backend, shots=1000)` | Deprecation -> `qiskit.execute` is deprecated. Replaced by `qiskit.primitives` | Internal Knowledge | `qiskit.execute` | `job = backend.run(qc, shots=1000)` |
| 24 | `counts = job.result().get_counts(qc)` | Deprecation -> The `get_counts` method is deprecated when passed a QuantumCircuit. | Internal Knowledge | `job.result().get_counts(qc)` | `counts = job.result().get_counts()` |


```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend 
from qiskit.visualization import plot_histogram
from qiskit.providers.job import job_monitor
import matplotlib.pyplot as plt
from qiskit.primitives import Sampler
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

sampler = Sampler()
job = sampler.run(qc)
result = job.result()
statevector = result.quasi_dists[0].binary_probabilities()

backend = AerSimulator()
job = backend.run(qc, shots=1000)

job_monitor(job)
counts = job.result().get_counts()
plot_histogram(counts)
```