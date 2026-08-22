| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> The plot_histogram() function is deprecated | qrn_notax_ddbb--4194776d-c578-4b79-8dc6-9c5e286bc808 | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 3 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> The job_monitor function is deprecated | qrn_notax_ddbb--b8601747-ed0a-4488-b998-af8f180f99be | qiskit.tools.monitor | `from qiskit.utils import job_monitor` |
| 7 | `simulator = getBackend.get_backend('statevector_simulator')` | Deprecation -> The get_backend() function is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | getBackend | `from qiskit_aer import Aer\nsimulator = Aer.get_backend('statevector_simulator')` |
| 10 | `result = execute(qc, simulator).result()` | Deprecation -> The execute() function is deprecated | qrn_notax_ddbb--7dcaf104-d552-4d87-994a-c7691846d9a9 | execute | `transpiled_circuit = transpile(qc, simulator)\nresult = simulator.run(transpiled_circuit).result()` |
| 12 | `backend = getBackend.get_backend('qasm_simulator')` | Deprecation -> The get_backend() function is deprecated | qrn_notax_ddbb--aa6cda1f-af91-4940-8d4c-1897f9a56701 | getBackend | `backend = Aer.get_backend('qasm_simulator')` |

```python
from qiskit import QuantumCircuit
from mylib import getBackend
from qiskit.visualization import plot_histogram
from qiskit.utils import job_monitor
import matplotlib.pyplot as plt
from qiskit_aer import Aer

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = Aer.get_backend('statevector_simulator')
transpiled_circuit = transpile(qc, simulator)
result = simulator.run(transpiled_circuit).result()
statevector = result.get_statevector()

backend = Aer.get_backend('qasm_simulator')
transpiled_circuit = transpile(qc, backend)
job = backend.run(transpiled_circuit, shots=1000)

job_monitor(job)
counts = job.result().get_counts(qc)
plot_histogram(counts)
```