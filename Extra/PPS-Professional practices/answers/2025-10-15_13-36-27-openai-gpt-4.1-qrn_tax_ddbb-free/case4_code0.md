| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.tools.visualization import plot_histogram | Import Path Change -> `qiskit.tools.visualization.plot_histogram` moved to `qiskit.visualization.plot_histogram` | qrn_tax_ddbb-3b87de12-a437-43a7-ae80-99bb0f6c289f | qiskit.tools.visualization.plot_histogram | from qiskit.visualization import plot_histogram |
| 4 | from qiskit.tools.monitor import job_monitor | Import Path Change -> `qiskit.tools.monitor.job_monitor` moved to `qiskit_aer.utils.job_monitor` | qrn_tax_ddbb-ac5821b9-2c77-4d8a-9786-d649d5d7053a | qiskit.tools.monitor.job_monitor | from qiskit_aer.utils import job_monitor |
| 13 | simulator = getBackend.get_backend('statevector_simulator') | API Change -> `get_statevector()` superseded by `result.data().get('statevector')` | qrn_tax_ddbb-2d532abb-f8a9-4582-a7da-c9a7e0b6dea7 | get_statevector | statevector = result.data().get('statevector') |
| 19 | job_monitor(job) | Import Path Change -> `qiskit.tools.monitor.job_monitor` moved to `qiskit_aer.utils.job_monitor` | qrn_tax_ddbb-ac5821b9-2c77-4d8a-9786-d649d5d7053a | job_monitor | job_monitor(job) |

```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
from qiskit_aer.utils import job_monitor
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = getBackend.get_backend('statevector_simulator')
result = execute(qc, simulator).result()
statevector = result.data().get('statevector')

backend = getBackend.get_backend('qasm_simulator')
job = execute(qc, backend, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```