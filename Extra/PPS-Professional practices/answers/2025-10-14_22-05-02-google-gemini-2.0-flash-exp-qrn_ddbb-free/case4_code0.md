| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` | Updated -> The `execute` function and `getBackend` module have been replaced. | IK | execute, getBackend | `from qiskit.providers import backend_to_options, BackendV1 as Backend` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> Module `qiskit.tools.visualization` is deprecated | qrn_ddbb-bb89e4091d208c9379959ac59bfd9f68 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> Module `qiskit.tools.monitor` is deprecated | qrn_ddbb-aa315d89b410a73442dc20668c69e5b3 | qiskit.tools.monitor |  |
| 14 | `simulator = getBackend.get_backend('statevector_simulator')` | Updated ->  `get_backend` is deprecated. | IK | getBackend | `simulator = Backend.get_backend('statevector_simulator')` |
| 15 | `result = execute(qc, simulator).result()` | Updated -> The `execute` function has been replaced. | IK | execute | `result = simulator.run(qc).result()` |
| 17 | `backend = getBackend.get_backend('qasm_simulator')` | Updated ->  `get_backend` is deprecated. | IK | getBackend | `backend = Backend.get_backend('qasm_simulator')` |
| 18 | `job = execute(qc, backend, shots=1000)` | Updated -> The `execute` function has been replaced. | IK | execute | `job = backend.run(qc, shots=1000)` |
| 20 | `job_monitor(job)` | Deprecation -> `job_monitor` is deprecated. | qrn_ddbb-aa315d89b410a73442dc20668c69e5b3 | qiskit.tools.monitor |  |

```python
from qiskit import QuantumCircuit
from qiskit.providers import backend_to_options, BackendV1 as Backend
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = Backend.get_backend('statevector_simulator')
result = simulator.run(qc).result()
statevector = result.get_statevector()

backend = Backend.get_backend('qasm_simulator')
job = backend.run(qc, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```