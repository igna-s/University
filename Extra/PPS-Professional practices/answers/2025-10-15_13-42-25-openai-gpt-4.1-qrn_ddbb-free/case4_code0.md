| Line | Code | Scenario | Reference | Artifact | Refactoring |   
| :--: | :--- | :------- | :-------: | :------- | :---------- | 
| 3 | from qiskit.tools.visualization import plot_histogram | Moved -> plot_histogram() has moved from qiskit.tools.visualization to qiskit.visualization | qrn_notax_ddbb--3dbe9c11-4652-487d-b9aa-32a898e06860 | qiskit.tools.visualization.plot_histogram | from qiskit.visualization import plot_histogram | 
| 4 | from qiskit.tools.monitor import job_monitor | Moved -> job_monitor() has moved from qiskit.tools.monitor to qiskit.providers.jobstatus or qiskit.visualization or qiskit.providers.job | qrn_notax_ddbb--0e19eec9-7198-41fc-b81a-a5e51dbb56a9 | qiskit.tools.monitor.job_monitor | from qiskit.providers.job import job_monitor | 

```python
from qiskit import QuantumCircuit
from mylib import execute, getBackend
from qiskit.visualization import plot_histogram
from qiskit.providers.job import job_monitor
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