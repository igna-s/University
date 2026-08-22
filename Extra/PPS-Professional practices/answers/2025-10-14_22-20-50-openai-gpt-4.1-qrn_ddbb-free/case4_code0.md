| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 3 | from qiskit.tools.visualization import plot_histogram | Deprecation -> qiskit.tools.visualization module is deprecated; use qiskit.visualization | qrn_ddbb-8d981a2b-adbb-4650-9a61-dcee319ce4ab | qiskit.tools.visualization | from qiskit.visualization import plot_histogram |
| 4 | from qiskit.tools.monitor import job_monitor | Deprecation -> qiskit.tools.monitor module is deprecated and removed in 1.0 | qrn_ddbb-c3ab7c3b-c399-447f-ad0a-08652e937d65 | qiskit.tools.monitor |  |
| 14 | job_monitor(job) | Deprecation -> job_monitor function removed with qiskit.tools.monitor | qrn_ddbb-c3ab7c3b-c399-447f-ad0a-08652e937d65 | job_monitor |  |

```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
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

counts = job.result().get_counts(qc)
plot_histogram(counts)
```