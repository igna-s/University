| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> qiskit.tools.visualization module is deprecated | b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> qiskit.tools.monitor module is deprecated | d88871b4-b5fd-45b3-b435-712e13d39ff9 | qiskit.tools.monitor | `from qiskit.utils import job_monitor` |

```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
from qiskit.utils import job_monitor
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