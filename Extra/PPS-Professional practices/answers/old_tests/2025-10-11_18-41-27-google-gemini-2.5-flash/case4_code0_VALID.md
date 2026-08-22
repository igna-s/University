| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :---------: | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram                   # type: ignore` | Deprecation -> plot_histogram moved to qiskit.visualization.plot_histogram | * | internal | qiskit.tools.visualization.plot_histogram | `from qiskit.visualization import plot_histogram  # type: ignore` |
| 4 | `from qiskit.tools.monitor import job_monitor                        # type: ignore` | Deprecation -> job_monitor moved to qiskit.providers.jobmonitor.job_monitor | * | internal | qiskit.tools.monitor.job_monitor | `from qiskit.providers.jobmonitor import job_monitor  # type: ignore` |

```python
from qiskit import QuantumCircuit  # type: ignore
from mylib import execute, getBackend  # type: ignore
from qiskit.visualization import plot_histogram  # type: ignore
from qiskit.providers.jobmonitor import job_monitor  # type: ignore
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = getBackend.get_backend('statevector_simulator')
result = execute(qc, simulator).result()
statevector = result.get_statevector()

backend = getBackend.get_backend('qasm_simulator')
job = execute(qc, backend, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```