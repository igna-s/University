| Line | Code | Scenario | Scenario Id | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :--------- | :-------: | :------- | :---------- |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The `qiskit.tools.visualization` module has been deprecated. | * | b3740733-db29-41f9-831a-0c2f81007982 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The `qiskit.tools.monitor` module has been deprecated. | * | f924db6c-9233-4c2c-a92e-a7357f6c4ea3 | qiskit.tools.monitor | |
| 17 | `job_monitor(job)` | Deprecation -> The `job_monitor` utility is deprecated and will be removed in Qiskit 1.0.0. | * | f924db6c-9233-4c2c-a92e-a7357f6c4ea3 | job_monitor | |


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