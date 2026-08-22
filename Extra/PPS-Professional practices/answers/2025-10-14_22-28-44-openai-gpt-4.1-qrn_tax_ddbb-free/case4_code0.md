| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | from qiskit.tools.visualization import plot_histogram | Deprecation -> plot_histogram() moved from qiskit.tools.visualization to qiskit.visualization | qrn_tax_ddbb-bd6b150d5920e605e51a3ac1fe105415 | plot_histogram | from qiskit.visualization import plot_histogram | 
| 4 | from qiskit.tools.monitor import job_monitor | Deprecation -> job_monitor moved from qiskit.tools.monitor to qiskit.providers.jobstatus | qrn_tax_ddbb-7d9882340bc492a6917bb1128a1e35c9 | job_monitor | from qiskit.providers.jobstatus import job_monitor | 

```python  
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
from qiskit.providers.jobstatus import job_monitor
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