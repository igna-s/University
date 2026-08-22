| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from mylib import execute, getBackend` |  Relocation -> The location of `execute` has been moved | IK | qiskit.execute | `from qiskit.providers import execute` |
| 2 | `from mylib import execute, getBackend` |  Relocation -> The location of `getBackend` has been moved | IK | qiskit.getBackend | `from qiskit.providers import get_backend` |
| 3 | `from qiskit.tools.visualization import plot_histogram` | Deprecation -> `qiskit.tools.visualization` is deprecated | qrn_tax_ddbb-e98b8b2b2ca949b1a3a623c38999c5ca | qiskit.tools.visualization | `from qiskit.visualization import plot_histogram` |
| 4 | `from qiskit.tools.monitor import job_monitor` | Deprecation -> `qiskit.tools.monitor` is deprecated | qrn_tax_ddbb-2ca55ca354ae4561a24c69e1c58175e9 | qiskit.tools.monitor |  |
| 14 | `simulator = getBackend.get_backend('statevector_simulator')` |  Updated ->  `get_backend` call update | IK | qiskit.getBackend | `simulator = get_backend('statevector_simulator')` |
| 15 | `result = execute(qc, simulator).result()` |  Relocation -> `execute` function has been moved | IK | qiskit.execute | `result = execute(qc, simulator, shots=1000).result()` |
| 17 | `backend = getBackend.get_backend('qasm_simulator')` |  Updated ->  `get_backend` call update | IK | qiskit.getBackend | `backend = get_backend('qasm_simulator')` |
| 18 | `job = execute(qc, backend, shots=1000)` |  Relocation -> `execute` function has been moved | IK | qiskit.execute | `job = execute(qc, backend, shots=1000)` |
| 20 | `job_monitor(job)` | Deprecation -> `job_monitor` is deprecated | qrn_tax_ddbb-2ca55ca354ae4561a24c69e1c58175e9 | qiskit.tools.monitor |  |

```python
from qiskit import QuantumCircuit
from qiskit.providers import execute, get_backend
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

qc = QuantumCircuit(2, 2)
qc.h(0)
qc.cx(0, 1)
qc.measure([0, 1], [0, 1])

print("Circuito cuántico:")
print(qc.draw(output='text'))

simulator = get_backend('statevector_simulator')
result = execute(qc, simulator, shots=1000).result()
statevector = result.get_statevector()

backend = get_backend('qasm_simulator')
job = execute(qc, backend, shots=1000)

counts = job.result().get_counts(qc)
plot_histogram(counts)
```