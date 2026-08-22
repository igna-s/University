| Line | Code | Scenario | Reference | Artifact | Refactoring |
| :--: | :--- | :------- | :-------: | :------- | :---------- |
| 2 | `from utils import createBackendAndrunJob` | Removal -> The utils module is removed | IK | utils |  |
| 6 | `job = createBackendAndrunJob()` | Removal -> The utils module is removed | IK | utils | `from qiskit import transpile, execute` |
| 6 | `job = createBackendAndrunJob()` | Change -> Replace createBackendAndrunJob with backend and execute | IK | createBackendAndrunJob | `backend = AerSimulator()`<br>`qc_transpiled = transpile(qc, backend)`<br>`job = execute(qc_transpiled, backend)` |
| 8 | `TextProgressBar().update(job)` | Deprecation -> Class TextProgressBar is deprecated | IK | TextProgressBar |  |
| 9 | `result = job.result()` | Change -> result.get_counts() needs the qc transpiled  | IK | result | `result = job.result()`<br>`counts = result.get_counts(qc_transpiled)` |

```python
from qiskit import QuantumCircuit
from qiskit import transpile, execute
from qiskit.quantum_info import Statevector
from qiskit_aer import AerSimulator

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)
qc.measure_all()

backend = AerSimulator()
qc_transpiled = transpile(qc, backend)
job = execute(qc_transpiled, backend)

result = job.result()
counts = result.get_counts(qc_transpiled)
```